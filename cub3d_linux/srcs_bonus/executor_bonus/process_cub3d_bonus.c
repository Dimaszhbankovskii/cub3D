#include "cub3d_bonus.h"

static void	set_default_ray(t_main *data)
{
	data->ray.dir = set_point(0, 0);
	data->ray.delta = set_point(0, 0);
	data->ray.side = set_point(0, 0);
	data->ray.i = 0;
	data->ray.step_x = 0;
	data->ray.step_y = 0;
	data->ray.intersect_y = 0;
}

static void	define_default_data(t_main *data)
{
	data->count_textures = 0;
	data->ceil_color = DEFAULT_CEIL_COLOR;
	data->floor_color = DEFAULT_FLOOR_COLOR;
	data->map.height = 0;
	data->map.width = 0;
	data->map.x = 0;
	data->map.y = 0;
	data->hero.pos = set_point(0, 0);
	data->hero.dir = set_point(0, 0);
	data->plane = set_point(0, 0);
	set_default_ray(data);
	data->wall.height = 0;
	data->wall.top = 0;
	data->wall.x = 0;
	data->wall.y = 0;
	data->wall.distance = 0;
}

static void	init_mlx_elements(t_main *data)
{
	data->mlx.prt = mlx_init();
	if (!data->mlx.prt)
		end_program(data, ERROR_MLX_INIT, 1);
	data->mlx.win = mlx_new_window(data->mlx.prt, WINDOW_WIDTH, \
	WINDOW_HEIGHT, WINDOW_TITLE);
	if (!data->mlx.win)
		end_program(data, ERROR_MLX_NEW_WINDOW, 1);
	data->mlx.img.prt = mlx_new_image(data->mlx.prt, WINDOW_WIDTH, \
	WINDOW_HEIGHT);	
	if (!data->mlx.img.prt)
		end_program(data, ERROR_MLX_NEW_IMAGE, 1);
	data->mlx.img.address = mlx_get_data_addr(data->mlx.img.prt, \
	&data->mlx.img.bits_per_pixel, &data->mlx.img.size_line, \
	&data->mlx.img.endian);
	if (!data->mlx.img.address)
		end_program(data, ERROR_MLX_GET_DATA_ADDR, 1);	
}

void	process_cub3d(t_main *data)
{
	define_default_data(data);
	init_mlx_elements(data);
	parse_file_to_tokens(data);
	parse_textures(data);
	parse_map(data);
	rendering_image(data);
	update_rmap(data);
	mlx_hook(data->mlx.win, 2, 1L << 0, &press_key, data);
	mlx_hook(data->mlx.win, 17, 1L << 0, close_window, data);
	mlx_loop(data->mlx.prt);
}
