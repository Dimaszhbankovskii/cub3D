/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:56:54 by vjose             #+#    #+#             */
/*   Updated: 2022/09/24 15:56:49 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_mlx_elements(t_main *data)
{
	int	i;

	i = -1;
	while (++i < WALL_TEXTURE)
	{
		if (data->textures[i].prt)
			mlx_destroy_image(data->mlx.prt, data->textures[i].prt);
	}
	if (data->mlx.img.prt)
		mlx_destroy_image(data->mlx.prt, data->mlx.img.prt);
	if (data->mlx.win)
		mlx_destroy_window(data->mlx.prt, data->mlx.win);
}

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
		free_mlx_elements(data);
	}
	if (error_num)
		ft_putstr_fd(error_mess, STDERR_FILENO);
	exit(error_num);
}
