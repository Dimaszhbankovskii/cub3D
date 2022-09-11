#include "cub3D.h"

static void	move_hero(int keycode, t_main *data)
{
	if (keycode == MOVE_AHEAD)
	{
		data->hero_pos_x += data->vector_x * MOVE_STEP;
		data->hero_pos_y += data->vector_y * MOVE_STEP;
	}
	else if (keycode == MOVE_LEFT)
	{
		data->hero_pos_x -= data->vector_x * MOVE_STEP;
		data->hero_pos_y += data->vector_y * MOVE_STEP;
	}
	else if (keycode == MOVE_RIGHT)
	{
		data->hero_pos_x += data->vector_x * MOVE_STEP;
		data->hero_pos_y -= data->vector_y * MOVE_STEP;
	}
	else if (keycode == MOVE_BACKWARD)
	{
		data->hero_pos_x -= data->vector_x * MOVE_STEP;
		data->hero_pos_y -= data->vector_y * MOVE_STEP;
	}
}

int press_key(int keycode, t_main *data)
{
	if (keycode == KEY_ESC)
	{
		// free_data();
		exit(0);
	}
	else if (keycode == MOVE_AHEAD || keycode == MOVE_BACKWARD || \
	keycode == MOVE_LEFT || keycode == MOVE_RIGHT)
		move_hero(keycode, data);
	else if (keycode == MOVE_ANGLE_RIGHT)
		data->hero_angle += ANGLE_STEP;
	else if (keycode == MOVE_ANGLE_LEFT)
		data->hero_angle -= ANGLE_STEP;

	// клавиши смены цвета пола и потолка

	data->vector_y = sin(data->hero_angle);
	data->vector_x = cos(data->hero_angle);
	return (0);
}

void	init_game_cub3d(t_main *data)
{
	// перехват клавиш
	mlx_hook(data->mlx_window, 2, 1L << 0, press_key, data);

	// перехват выхода
	// инициализация после перехвата
	mlx_loop_hook(data->mlx, loop_cub3d, data);
	mlx_loop(data->mlx);
}
