#include "cub3d.h"

static void	fail_prepare_rgb(t_main *data, \
char **tmp1, char **tmp2, char *mess)
{
	free_two_array_char(tmp1);
	free_two_array_char(tmp2);
	end_program(data, mess, 1);
}

static char	**prepare_rgb(char *line, t_main *data)
{
	char 	**tmp1;
	char	**tmp2;
	int		i;

	tmp1 = ft_split(line, ',');
	tmp2 = malloc_two_array_char(tmp1);
	if (size_two_array_char(tmp1) != 3 || !tmp2)
		fail_prepare_rgb(data, tmp1, tmp2, ERROR_FORMAT_RGB);
	i = 0;
	while (tmp1 && tmp1[i])
	{
		tmp2[i] = ft_strtrim(tmp1[i], SEP);
		if (!tmp2[i])
			fail_prepare_rgb(data, tmp1, tmp2, ERROR_FT_STRTRIM);
		i++;
	}
	free_two_array_char(tmp1);
	return (tmp2);
}

static void	define_rgb(char *line, t_main *data)
{
	char	**tmp;
	int		i;

	tmp = prepare_rgb(line, data);
	i = 0;
	while (tmp && tmp[i])
	{
		if (!ft_str_isdigit(tmp[i]) || ft_strlen(tmp[i]) > 3)
		{
			free_two_array_char(tmp);
			end_program(data, ERROR_FORMAT_RGB, 1);
		}
		i++;
	}
	data->color.r = (unsigned int)ft_atoi(tmp[0]);
	data->color.g = (unsigned int)ft_atoi(tmp[1]);
	data->color.b = (unsigned int)ft_atoi(tmp[2]);
	free_two_array_char(tmp);
}

void	parse_texture_ceil_floor(t_main *data, char *line)
{
	char	*tmp;

	tmp = line + 1;
	while (tmp && *tmp && ft_strchr(SEP, *tmp))
		tmp++;
	define_rgb(tmp, data);
	if (data->color.r > 255 || data->color.g > 255 || \
	data->color.b > 255)
		end_program(data, ERROR_FORMAT_RGB, 1);
	if (*line == 'C')
		data->ceil_color = ((data->color.r << 16) | \
		(data->color.g << 8) | data->color.b);
	else if (*line == 'F')
		data->floor_color = ((data->color.r << 16) | \
		(data->color.g << 8) | data->color.b);
	data->count_textures++;
}
