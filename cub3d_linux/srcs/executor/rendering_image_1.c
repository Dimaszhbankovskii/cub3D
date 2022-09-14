#include "cub3d.h"

static void	define_ray_step_side_x(t_main *data)
{
	if (data->ray.dir.x < 0)
	{
		data->ray.step_x = -1;
		data->ray.side.x = (data->hero.pos.x - data->map.x) * \
		data->ray.delta.x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.side.x = (data->map.x + 1.0 - data->hero.pos.x) * \
		data->ray.delta.x;
	}
}

static void	define_ray_step_side_y(t_main *data)
{
	if (data->ray.dir.y < 0)
	{
		data->ray.step_y = -1;
		data->ray.side.y = (data->hero.pos.y - data->map.y) * \
		data->ray.delta.y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.side.y = (data->map.y + 1.0 - data->hero.pos.y) * \
		data->ray.delta.y;
	}
}


static void	define_ray(t_main *data)
{
	double	camera_x;

	camera_x = 2.0 * data->ray.i / WINDOW_WIDTH - 1.0;
	data->ray.dir.x = data->hero.dir.x + data->plane.x * camera_x;
	data->ray.dir.y = data->hero.dir.y + data->plane.y * camera_x;
	data->map.x = (int)data->hero.pos.x;
	data->map.y = (int)data->hero.pos.y;
	data->ray.delta.x = fabs(1 / data->ray.dir.x);
	data->ray.delta.y = fabs(1 / data->ray.dir.y);
	define_ray_step_side_x(data);
	define_ray_step_side_y(data);
}

static void	intersect_ray(t_main *data)
{
	int	flag_stop;

	flag_stop = 0;
	while (!flag_stop)
	{
		if (data->ray.side.x < data->ray.side.y)
		{
			data->ray.side.x += data->ray.delta.x;
			data->map.x += data->ray.step_x;
			data->ray.intersect_y = 0;
		}
		else
		{
			data->ray.side.y += data->ray.delta.y;
			data->map.y += data->ray.step_y;
			data->ray.intersect_y = 1;
		}
		if (data->map.pr[data->map.y][data->map.x] == '1')
			flag_stop = 1;
	}
}

void	rendering_image(t_main *data)
{
	set_color_ceil_floor(data);
	data->ray.i = 0;
	while (data->ray.i < WINDOW_WIDTH)
	{
		define_ray(data);
		intersect_ray(data);
		define_wall(data);
		define_wall_x(data);
		rendering_wall(data);
		data->ray.i++;
	}
	mlx_put_image_to_window(data->mlx.prt, data->mlx.win, \
	data->mlx.img.prt, 0, 0);
}
