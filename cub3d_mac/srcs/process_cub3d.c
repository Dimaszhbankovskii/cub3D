#include "cub3D.h"

static void	define_data(t_main *data) // определить оставшиеся
{
	data->window_width = WINDOW_WIDTH;
	data->window_height = WINDOW_HEIGHT;
	data->count_textures = 0;
	data->ceil_color = DEFAULT_CEIL_COLOR;
	data->old_ceil_color = DEFAULT_OLD_CEIL_COLOR;
	data->floor_color = DEFAULT_FLOOR_COLOR;
	data->old_floor_color = DEFAULT_OLD_FLOOR_COLOR;
	data->amount_map_rows = 0;
	data->max_map_width = 0;
}

static void	define_alloc_data(t_main *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		end_program(data, ERROR_MLX_INIT, 1);
	data->rays = (t_ray *)malloc(sizeof(t_ray) * data->window_width);
	if (!data->rays)
		end_program(data, ERROR_MALLOC, 1);
}

static void	init_window_image(t_main *data)
{
	data->mlx_window = mlx_new_window(data->mlx, data->window_width, \
	data->window_height, WINDOW_TITLE);
	if (!data->mlx_window)
		end_program(data, ERROR_MLX_NEW_WINDOW, 1);
	data->image.prt = mlx_new_image(data->mlx, data->window_width, \
	data->window_height);
	if (!data->image.prt)
		end_program(data, ERROR_MLX_NEW_IMAGE, 1);
	data->image.img_address = (unsigned int *)mlx_get_data_addr(\
	data->image.prt, &data->image.bits_per_pixel, \
	&data->image.size_line, &data->image.endian);
	if (!data->image.img_address)
		end_program(data, ERROR_MLX_GET_DATA_ADDR, 1);	
}

void	process_cub3d(t_main *data)
{
    define_data(data);
    define_alloc_data(data);
	parse_file_to_tokens(data);
	parse_textures(data);
	parse_map(data);


	init_window_image(data);
	init_game_cub3d(data);
}
