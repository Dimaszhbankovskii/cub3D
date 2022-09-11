#include "cub3D.h"

static void	create_map(t_main *data)
{
	t_token			*tmp;
	unsigned int	i;

	tmp = find_token(&data->tokens, TOKEN_MAP);
	i = -1;
	while (++i < data->amount_map_rows)
	{
		data->map[i] = ft_strdup(tmp->line1);
		if (!data->map[i])
			end_program(data, ERROR_MALLOC, 1);
		tmp = tmp->next;
	}
	data->max_map_width = (unsigned int)ft_strlen(data->map[0]);
	i = 0;
	while (++i < data->amount_map_rows)
	{
		if (data->max_map_width < (unsigned int)ft_strlen(data->map[i]))
			data->max_map_width = (unsigned int)ft_strlen(data->map[i]);
	}
}

static void	create_rectangular_map(t_main *data)
{
	unsigned int	i;

	i = -1;
	while (++i < data->amount_map_rows)
	{
		data->rmap[i] = (char *)malloc(sizeof(char) * \
		(data->max_map_width + 1));
		if (!data->rmap[i])
			end_program(data, ERROR_MALLOC, 1);
		data->rmap[i][data->max_map_width] = '\0';
		ft_memcpy(data->rmap[i], data->map[i], ft_strlen(data->map[i]));
		ft_memset(data->rmap[i] + ft_strlen(data->map[i]), ' ', \
		data->max_map_width - (unsigned int)ft_strlen(data->map[i]));
	}
}

static void	define_position_hero(t_main *data, int row, int col)
{
	int	direction;

	direction = -1;
	data->hero_pos_x = col + 0.5;
	data->hero_pos_y = row + 0.5;
	if (data->map[row][col] == 'E')
		direction = 0;
	else if (data->map[row][col] == 'S')
		direction = 1;
	else if (data->map[row][col] == 'W')
		direction = 2;
	else if (data->map[row][col] == 'N')
		direction = 3;
	data->hero_angle = M_PI_2 * direction;
	data->map[row][col] = '0';
	data->rmap[row][col] = '0';
	data->vector_y = sin(data->hero_angle);
	data->vector_x = cos(data->hero_angle);
	data->center_ray = (float)data->window_width / 2;
	data->scale_column = 1 / (tan(M_PI_2 / data->window_width));
}

static void	check_map_characters(t_main *data)
{
	unsigned int	i;
	unsigned int	j;
	int				flag_hero;

	flag_hero = 0;
	i = -1;
	while (++i < data->amount_map_rows)
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (!ft_strchr(ALL_CHARACTERS, data->map[i][j]))
				end_program(data, ERROR_INVALID_CHR_MAP, 1);
			if (ft_strchr(HERO_CHARACTERS, data->map[i][j]))
			{
				if (flag_hero)
					end_program(data, ERROR_MANY_HEROES, 1);
				flag_hero = 1;
				define_position_hero(data, i, j);
			}
		}
	}
}

void	check_map_borders(t_main *data)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (++i < data->amount_map_rows)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (ft_strchr("0NSEW", data->map[i][j]))
			{
				if (i == 0 || (i == data->amount_map_rows - 1) || \
				j == 0 || (j == (unsigned int)ft_strlen(data->map[i]) - 1))
					end_program(data, ERROR_BORDERS_MAP, 1);
				if (data->rmap[i - 1][j] == ' ' || data->rmap[i + 1][j] == ' ' || \
				data->rmap[i][j - 1] == ' ' || data->rmap[i][j + 1] == ' ' || \
				data->rmap[i - 1][j - 1] == ' ' || data->rmap[i - 1][j + 1] == ' ' || \
				data->rmap[i + 1][j - 1] == ' ' || data->rmap[i + 1][j + 1] == ' ')
					end_program(data, ERROR_BORDERS_MAP, 1);
			}
			j++;
		}
	}
}

void	parse_map(t_main *data)
{
	t_token			*tmp;

	tmp = find_token(&data->tokens, TOKEN_MAP);
	while (tmp && tmp->type == TOKEN_MAP)
	{
		data->amount_map_rows++;
		tmp = tmp->next;
	}
	data->map = calloc_two_array_char(data->amount_map_rows);
	data->rmap = calloc_two_array_char(data->amount_map_rows);
	if (!data->map || !data->rmap)
		end_program(data, ERROR_MALLOC, 1);
	create_map(data);
	create_rectangular_map(data);
	check_map_characters(data);
	check_map_borders(data);
}
