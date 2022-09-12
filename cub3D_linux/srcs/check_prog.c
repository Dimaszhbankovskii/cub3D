#include "cub3D.h"

void	check_program(t_main *data)
{
	int	i;

	printf("--------------------------------------------------------\n");
	if (data->file.filename)
		printf("data->file.filename = %s\n", data->file.filename);
	else
		printf("data->file.filename = NULL\n");
	printf("--------------------------------------------------------\n");
	if (data->mlx)
		printf("data->mlx = mlx\n");
	else
		printf("data->mlx = NULL\n");
	printf("--------------------------------------------------------\n");
	if (data->mlx_window)
		printf("data->mlx_window = window\n");
	else
		printf("data->mlx_window = NULL\n");
	printf("--------------------------------------------------------\n");
	if (data->image.prt)
		printf("data->image.prt = image\n");
	else
		printf("data->image.prt = NULL\n");
	printf("--------------------------------------------------------\n");
	i = -1;
	while (++i < AMOUNT_TEXTURE)
	{
		if (data->textures[i].prt)
			printf("data->textures[%d].prt = prt\n", i);
		else
			printf("data->textures[%d].prt = NULL\n", i);
		if (data->textures[i].address)
			printf("data->textures[%d].texture_address = texture_address\n", i);
		else
			printf("data->textures[%d].texture_address = NULL\n", i);
	}
	printf("--------------------------------------------------------\n");
	printf("data->window_width = %u\n", data->window_width);
	printf("data->window_height = %u\n", data->window_height);
	printf("--------------------------------------------------------\n");
	printf("data->ceil_color = %u\n", data->ceil_color);
	printf("data->floor_color = %u\n", data->floor_color);
	printf("--------------------------------------------------------\n");
	printf("data->old_ceil_color = %u\n", data->old_ceil_color);
	printf("data->old_floor_color = %u\n", data->old_floor_color);
	printf("--------------------------------------------------------\n");
}

void	print_tokens(t_main *data)
{
	t_token	*tmp;

	tmp = data->tokens;
	if (tmp)
	{
		while (tmp)
		{
			if (tmp->line1)
				printf("token->line1(type = %d)==>%s<==\n", tmp->type, tmp->line1);
			else
				printf("token->line1==>NULL\n");
			tmp = tmp->next;
		}
	}
	else
		printf("data->tokens = NULL\n");
	printf("--------------------------------------------------------\n");
}

void	print_map(t_main *data)
{
	int	i;

	i = -1;
	while (++i < data->map.height)
		printf("\033[1;34m==>\033[0m%s\033[1;34m<==\033[0m\n", data->map.p[i]);
	printf("--------------------------------------------------------\n");
}

void	print_rmap(t_main *data)
{
	int	i;

	i = -1;
	printf("data->map.height = %d\n", data->map.height);
	printf("data->map.width = %d\n", data->map.width);
	printf("--------------------------------------------------------\n");
	while (++i < data->map.height)
		printf("\033[1;34m==>\033[0m%s\033[1;34m<==\033[0m\n", data->map.pr[i]);
	printf("--------------------------------------------------------\n");
}

void	print_hero(t_main *data)
{
	printf("data->hero.pos.x = %lf\n", data->hero.pos.x);
	printf("data->hero.pos.y = %lf\n", data->hero.pos.y);
	printf("data->hero.dir.x = %lf\n", data->hero.dir.x);
	printf("data->hero.dir.y = %lf\n", data->hero.dir.y);
	printf("--------------------------------------------------------\n");
}

void	print_plane(t_main *data)
{
	printf("data->plane.x = %lf\n", data->plane.x);
	printf("data->plane.y = %lf\n", data->plane.y);
	printf("--------------------------------------------------------\n");
}
