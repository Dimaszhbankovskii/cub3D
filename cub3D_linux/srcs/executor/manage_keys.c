#include "cub3D.h"

static void	move_ahead_backward(int keycode, t_main *data)
{
	if (keycode == MOVE_AHEAD)
	{
		if (data->hero.pos.x + data->hero.dir.x * MOVE_STEP > 1.1 && \
		data->hero.pos.x + data->hero.dir.x * MOVE_STEP < data->map.width - 1.1)
			data->hero.pos.x += data->hero.dir.x * MOVE_STEP;
		if (data->hero.pos.y + data->hero.dir.y * MOVE_STEP > 1.1 && \
		data->hero.pos.y + data->hero.dir.y * MOVE_STEP < data->map.height - 1.1)
			data->hero.pos.y += data->hero.dir.y * MOVE_STEP;
	}
	if (keycode == MOVE_BACKWARD)
	{
		if (data->hero.pos.x - data->hero.dir.x * MOVE_STEP > 1.1 && \
		data->hero.pos.x - data->hero.dir.x * MOVE_STEP < data->map.width - 1.1)
			data->hero.pos.x -= data->hero.dir.x * MOVE_STEP;
		if (data->hero.pos.y - data->hero.dir.y * MOVE_STEP > 1.1 && \
		data->hero.pos.y - data->hero.dir.y * MOVE_STEP < data->map.height - 1.1)
			data->hero.pos.y -= data->hero.dir.y * MOVE_STEP;
	}
	rendering_image(data);
}

static void	move_left_right(int keycode, t_main *data)
{
	if (keycode == MOVE_RIGHT)
	{
		if (data->hero.pos.x + data->plane.x * MOVE_STEP > 1.1 && \
		data->hero.pos.x + data->plane.x * MOVE_STEP < data->map.width - 1.1)
			data->hero.pos.x += data->plane.x * MOVE_STEP;
		if (data->hero.pos.y + data->plane.y * MOVE_STEP > 1.1 && \
		data->hero.pos.y + data->plane.y * MOVE_STEP < data->map.height - 1.1)
			data->hero.pos.y += data->plane.y * MOVE_STEP;
	}
	if (keycode == MOVE_LEFT)
	{
		if (data->hero.pos.x - data->plane.x * MOVE_STEP > 1.1 && \
		data->hero.pos.x - data->plane.x * MOVE_STEP < data->map.width - 1.1)
			data->hero.pos.x -= data->plane.x * MOVE_STEP;
		if (data->hero.pos.y - data->plane.y * MOVE_STEP > 1.1 && \
		data->hero.pos.y - data->plane.y * MOVE_STEP < data->map.height - 1.1)
			data->hero.pos.y -= data->plane.y * MOVE_STEP;
	}
	rendering_image(data);
}

static void	rotate_review(int keycode, t_main *data)
{
	double	tmp_dir_x;
	double	tmp_plane_x;

	tmp_dir_x = data->hero.dir.x;
	tmp_plane_x = data->plane.x;
	if (keycode == ROTATE_RIGHT)
	{
		data->hero.dir.x = data->hero.dir.x * cos(ANGLE_STEP) - data->hero.dir.y * sin(ANGLE_STEP);
		data->hero.dir.y = tmp_dir_x * sin(ANGLE_STEP) + data->hero.dir.y * cos(ANGLE_STEP);

		data->plane.x = data->plane.x * cos(ANGLE_STEP) - data->plane.y * sin(ANGLE_STEP);
		data->plane.y = tmp_plane_x * sin(ANGLE_STEP) + data->plane.y * cos(ANGLE_STEP);
	}
	if (keycode == ROTATE_LEFT)
	{
		data->hero.dir.x = data->hero.dir.x * cos(-ANGLE_STEP) - data->hero.dir.y * sin(-ANGLE_STEP);
		data->hero.dir.y = tmp_dir_x * sin(-ANGLE_STEP) + data->hero.dir.y * cos(-ANGLE_STEP);

		data->plane.x = data->plane.x * cos(-ANGLE_STEP) - data->plane.y * sin(-ANGLE_STEP);
		data->plane.y = tmp_plane_x * sin(-ANGLE_STEP) + data->plane.y * cos(-ANGLE_STEP);
	}
	rendering_image(data);
}

int press_key(int keycode, t_main *data)
{
	if (keycode == KEY_ESC)
		end_program(data, NULL, 0);
	else if (keycode == MOVE_AHEAD || keycode == MOVE_BACKWARD)
		move_ahead_backward(keycode, data);
	else if (keycode == MOVE_LEFT || keycode == MOVE_RIGHT)
		move_left_right(keycode, data);
	else if (keycode == ROTATE_LEFT || keycode == ROTATE_RIGHT)
		rotate_review(keycode, data);
	return (0);
}
