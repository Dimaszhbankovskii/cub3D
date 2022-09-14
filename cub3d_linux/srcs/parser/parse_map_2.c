#include "cub3d.h"

static int	check_chr_map(t_main *data, int j, int i)
{
	if (data->map.pr[i - 1][j] == ' ' || \
	data->map.pr[i + 1][j] == ' ' || \
	data->map.pr[i][j - 1] == ' ' || \
	data->map.pr[i][j + 1] == ' ' || \
	data->map.pr[i - 1][j - 1] == ' ' || \
	data->map.pr[i - 1][j + 1] == ' ' || \
	data->map.pr[i + 1][j - 1] == ' ' || \
	data->map.pr[i + 1][j + 1] == ' ')
		return (1);
	return (0);
}

void	check_map_borders(t_main *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map.height)
	{
		j = -1;
		while (data->map.p[i][++j])
		{
			if (ft_strchr("0", data->map.p[i][j]))
			{
				if (i == 0 || (i == data->map.height - 1) || \
				j == 0 || (j == (int)ft_strlen(data->map.p[i]) - 1))
					end_program(data, ERROR_BORDERS_MAP, 1);
				if (check_chr_map(data, j, i))
					end_program(data, ERROR_BORDERS_MAP, 1);
			}
		}
	}
}

void	update_rmap(t_main *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map.height)
	{
		j = -1;
		while (data->map.pr[i][++j])
		{
			if (data->map.pr[i][j] == ' ')
				data->map.pr[i][j] = '1';
		}
	}
}
