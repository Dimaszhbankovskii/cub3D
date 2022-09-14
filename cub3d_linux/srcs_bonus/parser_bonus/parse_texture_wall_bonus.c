#include "cub3d_bonus.h"

static void	define_texture_wall(t_main *data, char *path, int type)
{
	char	*tmp;
	int		len;

	tmp = path;
	len = ft_strlen(tmp);
	if (len < MIN_LEN_PATH_TEXTURE)
		end_program(data, ERROR_LEN_PATH_TEXTURE, 1);
	if (!ft_strcmp(tmp + len - LEN_EXTENSION, EXTENSION))
		data->textures[type].prt = mlx_xpm_file_to_image(\
		data->mlx.prt, path, (int *)&data->textures[type].width, \
		(int *)&data->textures[type].height);
	else
		end_program(data, ERROR_EXTENSION_TEXTURE, 1);
	if (!data->textures[type].prt && \
	data->textures[type].width != TEXTURE_SIZE && \
	data->textures[type].height != TEXTURE_SIZE)
		end_program(data, ERROR_OPEN_TEXTURE, 1);
	data->textures[type].address = (int *)mlx_get_data_addr(\
	data->textures[type].prt, &data->textures[type].bits_per_pixel, \
	&data->textures[type].size_line, &data->textures[type].endian);
	if (!data->textures[type].address)
		end_program(data, ERROR_MLX_GET_DATA_ADDR, 1);
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
	while (line && *(line + i) && ft_strchr(SEP, *(line + i)))
		i++;
	define_texture_wall(data, line + i, type_texture);
	data->count_textures++;
}
