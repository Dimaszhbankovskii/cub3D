#include "cub3d_bonus.h"

void	set_color_ceil_floor(t_main *data)
{
	int	i;
	int	j;
	
	i = -1;
	while (++i < WINDOW_HEIGHT / 2)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
			my_mlx_pixel_put(data, j, i, data->ceil_color);
	}
	while (++i < WINDOW_HEIGHT)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
			my_mlx_pixel_put(data, j, i, data->floor_color);
	}
}

void	define_wall(t_main *data)
{
	if (!data->ray.intersect_y)
		data->wall.distance = data->ray.side.x - data->ray.delta.x;
	else
		data->wall.distance = data->ray.side.y - data->ray.delta.y;
	data->wall.height = (int)(WINDOW_HEIGHT / data->wall.distance);
	data->wall.top = WINDOW_HEIGHT / 2 - data->wall.height / 2;
}

void	define_wall_x(t_main *data)
{
	double	wall_x;

	if (!data->ray.intersect_y)
		wall_x = data->hero.pos.y + data->wall.distance * \
        data->ray.dir.y;
	else
		wall_x = data->hero.pos.x + data->wall.distance * \
        data->ray.dir.x;
	wall_x -= floor(wall_x);
	data->wall.x = (int)(wall_x * TEXTURE_SIZE);
	if ((!data->ray.intersect_y && data->ray.dir.x > 0)
		|| (data->ray.intersect_y && data->ray.dir.y < 0))
		data->wall.x = TEXTURE_SIZE - data->wall.x - 1;
}

static int	get_color_pixel_wall(t_main *data, int x, int y)
{
	int	*wall;

	if (!data->ray.intersect_y)
	{
		if (data->ray.dir.x >= 0)
			wall = (int *)data->textures[TEXTURE_EA].address;
		else
			wall = (int *)data->textures[TEXTURE_WE].address;
	}
	else
	{
		if (data->ray.dir.y >= 0)
			wall = (int *)data->textures[TEXTURE_SO].address;
		else
			wall = (int *)data->textures[TEXTURE_NO].address;
	}
	return (wall[TEXTURE_SIZE * y + x]);
}

void	rendering_wall(t_main *data)
{
	double          attracted_step_y;
	int	color;
	int		        i;

	attracted_step_y = (double)TEXTURE_SIZE / (double)data->wall.height;
	data->wall.y = 0;
	i = 0;
	while (i < data->wall.height)
	{
		color = get_color_pixel_wall(data, data->wall.x, \
        (int)data->wall.y);
		my_mlx_pixel_put(data, data->ray.i, data->wall.top + i, color);
		data->wall.y += attracted_step_y;
		i++;
	}
}
