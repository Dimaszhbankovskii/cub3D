#include "cub3d_bonus.h"

static void	create_map(t_main *data)
{
	t_token	*tmp;
	int		i;

	tmp = find_token(&data->tokens, TOKEN_MAP);
	i = -1;
	while (++i < data->map.height)
	{
		data->map.p[i] = ft_strdup(tmp->line1);
		if (!data->map.p[i])
			end_program(data, ERROR_MALLOC, 1);
		tmp = tmp->next;
	}
	data->map.width = (int)ft_strlen(data->map.p[0]);
	i = 0;
	while (++i < data->map.height)
	{
		if (data->map.width < (int)ft_strlen(data->map.p[i]))
			data->map.width = (int)ft_strlen(data->map.p[i]);
	}
}

static void	create_rectangular_map(t_main *data)
{
	int	i;

	i = -1;
	while (++i < data->map.height)
	{
		data->map.pr[i] = (char *)malloc(sizeof(char) * \
		(data->map.width + 1));
		if (!data->map.pr[i])
			end_program(data, ERROR_MALLOC, 1);
		data->map.pr[i][data->map.width] = '\0';
		ft_memcpy(data->map.pr[i], data->map.p[i], \
		ft_strlen(data->map.p[i]));
		ft_memset(data->map.pr[i] + ft_strlen(data->map.p[i]), ' ', \
		data->map.width - (int)ft_strlen(data->map.p[i]));
	}
}

static void	define_position_hero(t_main *data, char dir, \
int row, int col)
{
	data->hero.pos = set_point(col + 0.5, row + 0.5);
	if (dir == 'E')
	{
		data->hero.dir = set_point(1, 0);
		data->plane = set_point(0, FOV);
	}
	else if (dir == 'W')
	{
		data->hero.dir = set_point(-1, 0);
		data->plane = set_point(0, -FOV);
	}
	else if (dir == 'S')
	{
		data->hero.dir = set_point(0, 1);
		data->plane = set_point(-FOV, 0);
	}
	else if (dir == 'N')
	{
		data->hero.dir = set_point(0, -1);
		data->plane = set_point(FOV, 0);
	}
	data->map.p[row][col] = '0';
	data->map.pr[row][col] = '0';
}

static void	check_map_characters(t_main *data)
{
	int	i;
	int	j;
	int	flag_hero;

	flag_hero = 0;
	i = -1;
	while (++i < data->map.height)
	{
		j = -1;
		while (data->map.p[i][++j])
		{
			if (!ft_strchr(ALL_CHARACTERS, data->map.p[i][j]))
				end_program(data, ERROR_INVALID_CHR_MAP, 1);
			if (ft_strchr(HERO_CHARACTERS, data->map.p[i][j]))
			{
				if (flag_hero)
					end_program(data, ERROR_MANY_HEROES, 1);
				flag_hero = 1;
				define_position_hero(data, data->map.p[i][j], i, j);
			}
		}
	}
	if (!flag_hero)
		end_program(data, ERROR_NO_HERO, 1);
}

void	parse_map(t_main *data)
{
	t_token			*tmp;

	tmp = find_token(&data->tokens, TOKEN_MAP);
	data->map.height = 0;
	while (tmp && tmp->type == TOKEN_MAP)
	{
		data->map.height++;
		tmp = tmp->next;
	}
	data->map.p = calloc_two_array_char(data->map.height);
	data->map.pr = calloc_two_array_char(data->map.height);
	if (!data->map.p || !data->map.pr)
		end_program(data, ERROR_MALLOC, 1);
	create_map(data);
	create_rectangular_map(data);
	check_map_characters(data);
	check_map_borders(data);
}
