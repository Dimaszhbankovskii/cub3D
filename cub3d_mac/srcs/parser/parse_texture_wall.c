#include "cub3D.h"

static void	define_texture_wall(t_main *data, char *path, int type)
{
	char	*tmp;
	int		len;

	tmp = path;
	len = ft_strlen(tmp);
	if (len < MIN_LEN_PATH_TEXTURE)
		end_program(data, ERROR_LEN_PATH_TEXTURE, 1);
	if (!ft_strcmp(tmp + len - LEN_EXTENSION, EXTENSION))
		data->textures[type].prt = mlx_xpm_file_to_image(data->mlx, path, (int *)&data->textures[type].texture_width, (int *)&data->textures[type].texture_height);
	else
		end_program(data, ERROR_EXTENSION_TEXTURE, 1);
	if (!data->textures[type].prt)
		end_program(data, ERROR_OPEN_TEXTURE, 1);
	get_texture_address(&data->textures[type], data);
	data->textures[type].width_to_height = data->textures[type].texture_width /\
	data->textures[type].texture_height;
}

void	parse_texture_wall(t_main *data, char *line)
{
    int		type_texture;
	int		i;

	type_texture = -1;
    if (!ft_strncmp(line, NO, ft_strlen(NO)))
		type_texture = TEXTURE_NO;
	else if (!ft_strncmp(line, SO, ft_strlen(SO)))
		type_texture = TEXTURE_SO;
	else if (!ft_strncmp(line, WE, ft_strlen(WE)))
		type_texture = TEXTURE_WE;
	else if (!ft_strncmp(line, EA, ft_strlen(EA)))
		type_texture = TEXTURE_EA;
	else
		end_program(data, ERROR_INVALID_TEXTURE, 1);
	i = 2;
	if (!ft_strchr(SEP, *(line + i)))
		end_program(data, ERROR_SEPARATOR_TEXTURE, 1);
	if (data->textures[type_texture].prt)
		end_program(data, ERROR_DUPLICATE_TEXTURE, 1);
	while (line && *(line + i) && ft_strchr(SEPARATORS, *(line + i)))
		i++;
	define_texture_wall(data, line + i, type_texture);
	data->count_textures++;
}
