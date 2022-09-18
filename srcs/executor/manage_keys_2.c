/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_keys_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:56:22 by vjose             #+#    #+#             */
/*   Updated: 2022/09/18 16:56:23 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_review_right(t_main *data)
{
	double	tmp_dir_x;
	double	tmp_plane_x;

	tmp_dir_x = data->hero.dir.x;
	tmp_plane_x = data->plane.x;
	data->hero.dir.x = data->hero.dir.x * cos(ANGLE_STEP) - \
	data->hero.dir.y * sin(ANGLE_STEP);
	data->hero.dir.y = tmp_dir_x * sin(ANGLE_STEP) + \
	data->hero.dir.y * cos(ANGLE_STEP);
	data->plane.x = data->plane.x * cos(ANGLE_STEP) - \
	data->plane.y * sin(ANGLE_STEP);
	data->plane.y = tmp_plane_x * sin(ANGLE_STEP) + \
	data->plane.y * cos(ANGLE_STEP);
	rendering_image(data);
}

void	rotate_review_left(t_main *data)
{
	double	tmp_dir_x;
	double	tmp_plane_x;

	tmp_dir_x = data->hero.dir.x;
	tmp_plane_x = data->plane.x;
	data->hero.dir.x = data->hero.dir.x * cos(-ANGLE_STEP) - \
	data->hero.dir.y * sin(-ANGLE_STEP);
	data->hero.dir.y = tmp_dir_x * sin(-ANGLE_STEP) + \
	data->hero.dir.y * cos(-ANGLE_STEP);
	data->plane.x = data->plane.x * cos(-ANGLE_STEP) - \
	data->plane.y * sin(-ANGLE_STEP);
	data->plane.y = tmp_plane_x * sin(-ANGLE_STEP) + \
	data->plane.y * cos(-ANGLE_STEP);
	rendering_image(data);
}

int	close_window(t_main *data)
{
	end_program(data, NULL, 0);
	return (0);
}
