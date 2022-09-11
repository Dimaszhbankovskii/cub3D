#include "cub3D.h"

static void	set_image_ceil_floor(t_main *data)
{
	unsigned int	i;
	unsigned int	amount_pixel;

	i = -1;
	amount_pixel = data->window_width * data->window_height;
	while (++i < amount_pixel / 2)
		data->image.img_address[i] = data->ceil_color;
	while (++i < amount_pixel)
		data->image.img_address[i] = data->floor_color;
}

static double	func(t_main *data, unsigned int ray, \
int *max_height, int *y)
{
	int	pos_y;

	if (data->rays[ray].height > data->window_height)
	{
		pos_y = (data->rays[ray].height - data->window_height) / 2;
		*y = -1;
		*max_height = data->window_height;
	}
	else
	{
		pos_y = 0;
		*y = -1 + (data->window_height - data->rays[ray].height) / 2;
		*max_height = *y + data->rays[ray].height;
	}
	return (pos_y);
}

static void	set_image_wall(t_main *data, unsigned int type, \
unsigned int ray)
{
	double			step;
	unsigned int	pos_x;
	double			pos_y;
	int				y;
	int				max_height;

	step = (double)data->textures[type].texture_height / data->rays[ray].height;

	pos_x = data->rays[ray].texture_position * data->textures[type].texture_width;
	
	pos_y = step * func(data, ray, &max_height, &y);
	
	while (++y < max_height)
	{
		data->image.img_address[y * data->window_width + ray] = data->textures[type].texture_address[(unsigned int)pos_y * data->textures[type].texture_width + pos_x];
		pos_y += step;
	}
}

static void	set_image_texture(t_main *data)
{
	unsigned int	ray;
	unsigned int	type_texture;

	ray = -1;
	type_texture = -1;
	while (++ray < data->window_width)
	{
		if (data->rays[ray].dir == 'N')
			type_texture = TEXTURE_NO;
		else if (data->rays[ray].dir == 'S')
			type_texture = TEXTURE_SO;
		else if (data->rays[ray].dir == 'W')
			type_texture = TEXTURE_WE;
		else if (data->rays[ray].dir == 'E')
			type_texture = TEXTURE_EA;
		set_image_wall(data, type_texture, ray);
	}
}

int	loop_cub3d(t_main *data)
{
	raycasting(data);
	set_image_ceil_floor(data);
	set_image_texture(data);
	mlx_put_image_to_window(data->mlx, data->mlx_window, \
	data->image.prt, 0, 0);	
	return (0);
}
