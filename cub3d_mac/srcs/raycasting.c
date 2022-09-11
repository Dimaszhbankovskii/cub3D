#include "cub3D.h"

# define EX_STEP_RAY 1
# define EY_STEP_RAY 2

# define SET_RAY_X 1
# define SET_RAY_Y 2

typedef struct s_position
{
	double	x;
	double	y;
}	t_position;

static t_position	set_position(double position_x, double position_y)
{
	t_position	position;

	position.x = position_x;
	position.y = position_y;
	return (position);
}

static int	define_ex_ey_step_ray(double angle, int type_e_step)
{
	int	res;

	res = 0;
	if (type_e_step == EX_STEP_RAY)
	{
		if (angle <= M_PI_2 || angle > 3 * M_PI_2)
			res = 1;
		else
			res = -1;
	}
	else if (type_e_step == EY_STEP_RAY)
	{
		if (angle < M_PI)
			res = -1;
		else
			res = 1;
	}
	return (res);
}

static unsigned int	convert_d(double value, double old_position)
{
	unsigned int	position;

	position = (unsigned int)value;
	if (fabs(position - old_position) > 1)
		position += 1;
	return (position);
}

static t_position	define_ray_intersect_x(double ex_step_ray, double y_step_ray, t_main *data)
{
	t_position	pos;
	t_position	old_pos;

	old_pos.x = data->hero_pos_x;
	old_pos.y = data->hero_pos_y;

	if (ex_step_ray > 0)
		pos = set_position((int)data->hero_pos_x + 1, data->hero_pos_y + y_step_ray * (1 - (data->hero_pos_x - (int)data->hero_pos_x)));
	else
		pos = set_position((int)data->hero_pos_x - 1, data->hero_pos_y + y_step_ray * (data->hero_pos_x - (int)data->hero_pos_x));

	while (pos.x >= 0 && pos.y >= 0 && pos.y < data->amount_map_rows && pos.x < data->max_map_width && data->rmap[convert_d(pos.y, old_pos.y)][(unsigned int)pos.x] != '1')
	{
		old_pos.x = pos.x;
		old_pos.y = pos.y;
		pos.x += ex_step_ray;
		pos.y += y_step_ray;
	}

	if (ex_step_ray < 0)
		pos.x += 1;
	return (pos);
}

static t_position	define_ray_intersect_y(double x_step_ray, double ey_step_ray, t_main *data)
{
	t_position	pos;
	t_position	old_pos;

	old_pos.x = data->hero_pos_x;
	old_pos.y = data->hero_pos_y;

	if (ey_step_ray > 0)
	{
		pos = set_position(data->hero_pos_x + x_step_ray * (1 - (data->hero_pos_y - (int)data->hero_pos_y)), (int)data->hero_pos_y + 1);
	}
	else
		pos = set_position(data->hero_pos_x + x_step_ray * (data->hero_pos_y - (int)data->hero_pos_y), (int)data->hero_pos_y - 1);
	// pos = set_position((int)data->hero_pos_y + 1, data->hero_pos_x + x_step_ray * (1 - (data->hero_pos_y - (int)data->hero_pos_y)));

	// printf("check 1.1\n");
	// printf("pos.y = %lf\n", pos.y);
	// printf("pos.x = %lf\n", pos.x);
	// printf("rmap[%u][%u] = %c\n", convert_d(pos.y, old_pos.y), convert_d(pos.x, old_pos.x), data->rmap[convert_d(pos.y, old_pos.y)][convert_d(pos.x, old_pos.x)]);

	while (pos.x >= 0 && pos.y >= 0 && pos.y < data->amount_map_rows && pos.x < data->max_map_width && data->rmap[(unsigned int)pos.y][convert_d(pos.x, old_pos.x)] != '1')
	{
		old_pos.x = pos.x;
		old_pos.y = pos.y;
		pos.x += x_step_ray;
		pos.y += ey_step_ray;
	}
	
	// printf("check 1.2\n");
	
	if (ey_step_ray < 0)
		pos.y += 1;
	return (pos);
}

static t_position	define_distance_x_y(t_main *data, t_position ray_intersect_x, t_position	ray_intersect_y)
{
	t_position	distance;

	distance = set_position(data->vector_x * (ray_intersect_x.x - data->hero_pos_x) + data->vector_y * (ray_intersect_x.y - data->hero_pos_y), \
	data->vector_x * (ray_intersect_y.x - data->hero_pos_x) + data->vector_y * (ray_intersect_y.y - data->hero_pos_y));

	return (distance);
}

static t_ray	set_ray(int type, t_position distance, t_position ray_intersect, t_main *data)
{
	t_ray	ray;

	if (type == SET_RAY_X)
	{
		ray.distance = distance.x;
		ray.height = data->scale_column / distance.x;
		ray.texture_position = ray_intersect.y - (int)ray_intersect.y;
		if (ray_intersect.x < data->hero_pos_x)
			ray.dir = 'W';
		else
			ray.dir = 'E';
	}
	else if (type == SET_RAY_Y)
	{
		ray.distance = distance.y;
		ray.height = data->scale_column / distance.y;
		ray.texture_position = ray_intersect.x - (int)ray_intersect.x;
		if (ray_intersect.y < data->hero_pos_y)
			ray.dir = 'N';
		else
			ray.dir = 'S';
	}	
	return (ray);
}

static void	calculate_raycasting(double angle, unsigned int ray, t_main *data)
{
	int			ex_step_ray;
	int			ey_step_ray;
	t_position	ray_intersect_x;
	t_position	ray_intersect_y;
	t_position	distance;

	ex_step_ray = define_ex_ey_step_ray(angle, EX_STEP_RAY);
	ey_step_ray = define_ex_ey_step_ray(angle, EY_STEP_RAY);

	// if (ray == 17)
	// 	printf("check 1\n");

	ray_intersect_x = define_ray_intersect_x(ex_step_ray, ex_step_ray * tan(angle), data);

	// if (ray == 17)
	// {
	// 	printf("check 2\n");
	// 	printf("ey_step_ray = %d\n", ey_step_ray);
	// 	printf("angle = %lf\n", angle);
	// }

	ray_intersect_y = define_ray_intersect_y(ey_step_ray / tan(angle), ey_step_ray, data);
	
	// if (ray == 17)
	// 	printf("check ...\n");

	// //===============
	// if (ray <= 25)
	// {
	// 	printf("ray = %u\n", ray);
	// 	printf("ray_intersecr_x.x = %lf\n", ray_intersect_x.x);
	// 	printf("ray_intersecr_x.y = %lf\n", ray_intersect_x.y);
	// 	printf("ray_intersecr_y.x = %lf\n", ray_intersect_y.x);
	// 	printf("ray_intersecr_y.y = %lf\n", ray_intersect_y.y);
	// 	printf("---------------------------------------------------\n");
	// }
	// //===============

	// //===============
	// if (ray == 17)
	// 	exit(0);
	// //===============

	distance = define_distance_x_y(data, ray_intersect_x, ray_intersect_y);
	
	if (distance.x < distance.y)
		data->rays[ray] = set_ray(SET_RAY_X, distance, ray_intersect_x, data);
	else
		data->rays[ray] = set_ray(SET_RAY_Y, distance, ray_intersect_y, data);
	
	if (data->rays[ray].dir == 'W' || data->rays[ray].dir == 'S')
		data->rays[ray].texture_position = 1.0 - data->rays[ray].texture_position;
}

void	raycasting(t_main *data)
{
	unsigned int	ray;
	double			angle;

	ray = 0;
	while (ray < data->window_width)
	{
		angle = data->hero_angle + atan(ray / data->center_ray - 1);
		if (angle < 0)
			angle += 2 * M_PI;
		else if (angle > 2 * M_PI)
			angle -= 2 * M_PI;
		calculate_raycasting(angle, ray, data);
		ray++;
	}
}
