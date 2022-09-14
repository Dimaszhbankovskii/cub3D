#include "cub3d.h"

static void	move_ahead(t_main *data)
{
	if (data->hero.pos.x + data->hero.dir.x * MOVE_STEP > 1.1 && \
	data->hero.pos.x + data->hero.dir.x * MOVE_STEP < \
	data->map.width - 1.1)
		data->hero.pos.x += data->hero.dir.x * MOVE_STEP;
	if (data->hero.pos.y + data->hero.dir.y * MOVE_STEP > 1.1 && \
	data->hero.pos.y + data->hero.dir.y * MOVE_STEP < \
	data->map.height - 1.1)
		data->hero.pos.y += data->hero.dir.y * MOVE_STEP;
	rendering_image(data);
}

static void	move_backward(t_main *data)
{
	if (data->hero.pos.x - data->hero.dir.x * MOVE_STEP > 1.1 && \
	data->hero.pos.x - data->hero.dir.x * MOVE_STEP < \
	data->map.width - 1.1)
		data->hero.pos.x -= data->hero.dir.x * MOVE_STEP;
	if (data->hero.pos.y - data->hero.dir.y * MOVE_STEP > 1.1 && \
	data->hero.pos.y - data->hero.dir.y * MOVE_STEP < \
	data->map.height - 1.1)
		data->hero.pos.y -= data->hero.dir.y * MOVE_STEP;
	rendering_image(data);
}

static void	move_right(t_main *data)
{
	if (data->hero.pos.x + data->plane.x * MOVE_STEP > 1.1 && \
	data->hero.pos.x + data->plane.x * MOVE_STEP < \
	data->map.width - 1.1)
		data->hero.pos.x += data->plane.x * MOVE_STEP;
	if (data->hero.pos.y + data->plane.y * MOVE_STEP > 1.1 && \
	data->hero.pos.y + data->plane.y * MOVE_STEP < \
	data->map.height - 1.1)
		data->hero.pos.y += data->plane.y * MOVE_STEP;
	rendering_image(data);
}

static void	move_left(t_main *data)
{
	if (data->hero.pos.x - data->plane.x * MOVE_STEP > 1.1 && \
	data->hero.pos.x - data->plane.x * MOVE_STEP < \
	data->map.width - 1.1)
		data->hero.pos.x -= data->plane.x * MOVE_STEP;
	if (data->hero.pos.y - data->plane.y * MOVE_STEP > 1.1 && \
	data->hero.pos.y - data->plane.y * MOVE_STEP < \
	data->map.height - 1.1)
		data->hero.pos.y -= data->plane.y * MOVE_STEP;
	rendering_image(data);
}

int press_key(int keycode, t_main *data)
{
	if (keycode == KEY_ESC)
		end_program(data, NULL, 0);
	else if (keycode == MOVE_AHEAD)
		move_ahead(data);
	else if (keycode == MOVE_BACKWARD)
		move_backward(data);
	else if (keycode == MOVE_RIGHT)
		move_right(data);
	else if (keycode == MOVE_LEFT)
		move_left(data);
	else if (keycode == ROTATE_RIGHT)
		rotate_review_right(data);	
	else if (keycode == ROTATE_LEFT)
		rotate_review_left(data);
	return (0);
}
