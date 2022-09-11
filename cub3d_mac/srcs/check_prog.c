#include "cub3D.h"

void	check_program(t_main *data)
{
	int	i;

	printf("--------------------------------------------------------\n");
	if (data->file.filename)
		printf("data->file.filename = %s\n", data->file.filename);
	else
		printf("data->file.filename = NULL\n");
	if (data->mlx)
		printf("data->mlx = mlx\n");
	else
		printf("data->mlx = NULL\n");
	if (data->mlx_window)
		printf("data->mlx_window = window\n");
	else
		printf("data->mlx_window = NULL\n");
	i = -1;
	while (++i < AMOUNT_TEXTURE)
	{
		if (data->textures[i].prt)
			printf("data->textures[%d].prt = prt\n", i);
		else
			printf("data->textures[%d].prt = NULL\n", i);
		if (data->textures[i].texture_address)
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
	printf("data->count_texture = %u\n", data->count_textures);
	// printf("data->amount_texture_rows = %u\n", data->amount_texture_rows);
	printf("data->amount_map_rows = %u\n", data->amount_map_rows);
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
}

void	print_map(t_main *data)
{
	unsigned int	i;

	i = -1;
	while (++i < data->amount_map_rows)
		printf("\033[1;34m==>\033[0m%s\033[1;34m<==\033[0m\n", data->map[i]);
}

void	print_rmap(t_main *data)
{
	unsigned int	i;

	i = -1;
	while (++i < data->amount_map_rows)
		printf("\033[1;34m==>\033[0m%s\033[1;34m<==\033[0m\n", data->rmap[i]);
}

void	print_ray(t_main *data, unsigned int ray)
{
	printf("ray = %4u  |  distance = %lf  |  height = %u  |  texture_position = %lf  |  dir = %c\n", \
	ray, data->rays[ray].distance, \
	data->rays[ray].height, data->rays[ray].texture_position, \
	data->rays[ray].dir);
}
