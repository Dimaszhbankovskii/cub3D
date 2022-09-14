#include "cub3d_bonus.h"

static void	move_ahead(t_main *data)
{
	if (data->map.p[(int)data->hero.pos.y]\
	[(int)(data->hero.pos.x + data->hero.dir.x * MOVE_STEP)] == '0')
		data->hero.pos.x += data->hero.dir.x * MOVE_STEP;
	if (data->map.p[(int)(data->hero.pos.y + \
	data->hero.dir.y * MOVE_STEP)][(int)data->hero.pos.x] == '0')
		data->hero.pos.y += data->hero.dir.y * MOVE_STEP;
	rendering_image(data);
}

static void	move_backward(t_main *data)
{
	if (data->map.p[(int)data->hero.pos.y]\
	[(int)(data->hero.pos.x - data->hero.dir.x * MOVE_STEP)] == '0')
		data->hero.pos.x -= data->hero.dir.x * MOVE_STEP;
	if (data->map.p[(int)(data->hero.pos.y - \
	data->hero.dir.y * MOVE_STEP)][(int)data->hero.pos.x] == '0')
		data->hero.pos.y -= data->hero.dir.y * MOVE_STEP;
	rendering_image(data);
}

static void	move_right(t_main *data)
{
	if (data->map.p[(int)data->hero.pos.y]\
	[(int)(data->hero.pos.x + data->plane.x * MOVE_STEP)] == '0')
		data->hero.pos.x += data->plane.x * MOVE_STEP;
	
	if (data->map.p[(int)(data->hero.pos.y + \
	data->plane.y * MOVE_STEP)][(int)data->hero.pos.x] == '0')
		data->hero.pos.y += data->plane.y * MOVE_STEP;
	rendering_image(data);
}

static void	move_left(t_main *data)
{
	if (data->map.p[(int)data->hero.pos.y]\
	[(int)(data->hero.pos.x - data->plane.x * MOVE_STEP)] == '0')
		data->hero.pos.x -= data->plane.x * MOVE_STEP;
	if (data->map.p[(int)(data->hero.pos.y - \
	data->plane.y * MOVE_STEP)][(int)data->hero.pos.x] == '0')
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
