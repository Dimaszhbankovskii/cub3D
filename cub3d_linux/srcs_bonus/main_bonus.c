#include "cub3d_bonus.h"

static void	check_file_extension(char const *filename)
{
	char	*tmp;

	tmp = ft_strrchr(filename, '.');
	if (!tmp || ft_strcmp(tmp, ".cub"))
		end_program(NULL, ERROR_FILE_EXTENSION, 1);
}

static void	init_data(t_main *data, char *filename)
{
	int	i;

	data->file.filename = filename;
	data->file.line = NULL;
	data->mlx.prt = NULL;
	data->mlx.win = NULL;
	data->mlx.img.prt = NULL;
	data->mlx.img.address = NULL;
	data->tokens = NULL;
	i = -1;
	while (++i < WALL_TEXTURE)
	{
		data->textures[i].prt = NULL;
		data->textures[i].address = NULL;
	}
	data->map.p = NULL;
	data->map.pr = NULL;
}

int	main(int argc, char **argv)
{
	t_main	data;

	if (argc != 2)
		end_program(NULL, ERROR_AMOUNT_ARGS, 1);
	check_file_extension(argv[1]);
	init_data(&data, argv[1]);
	data.file.fd = open(data.file.filename, O_RDONLY);
	if (data.file.fd < 0)
		end_program(NULL, ERROR_OPEN_FILE, 1);
	process_cub3d(&data);
	close(data.file.fd);
	return (0);
}
