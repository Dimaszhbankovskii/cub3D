#include "cub3d_bonus.h"

t_point	set_point(double x, double y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

void	my_mlx_pixel_put(t_main *data, int x, int y, \
unsigned int color)
{
	char	*dst;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		dst = data->mlx.img.address + (y * data->mlx.img.size_line + \
		x * (data->mlx.img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
