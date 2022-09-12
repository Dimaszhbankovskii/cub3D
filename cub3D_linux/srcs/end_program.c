#include "cub3D.h"

void	end_program(t_main *data, char *error_mess, int error_num)
{
	if (data)
	{
		if (data->file.line)
			free (data->file.line);
		if (data->tokens)
			free_tokens(data);
		if (data->map.p)
			free_two_array_char(data->map.p);
		if (data->map.pr)
			free_two_array_char(data->map.pr);
	}
	if (error_num)
		ft_putstr_fd(error_mess, STDERR_FILENO);
	exit(error_num);
}

