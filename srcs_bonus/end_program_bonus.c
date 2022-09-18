/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:57:15 by vjose             #+#    #+#             */
/*   Updated: 2022/09/18 17:20:34 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	// if (data->mlx.prt)
	// {
	// 	mlx_destroy_display(data->mlx.prt);
	// 	free (data->mlx.prt);
	// }
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
