/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:56:48 by vjose             #+#    #+#             */
/*   Updated: 2022/09/18 16:56:49 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_textures(t_main *data)
{
	t_token	*tmp;

	tmp = data->tokens;
	while (tmp && data->count_textures != ALL_TEXTURE)
	{
		if (tmp->type == TOKEN_TEXTURE)
		{
			if (*tmp->line2 == 'N' || *tmp->line2 == 'S' || \
			*tmp->line2 == 'E' || *tmp->line2 == 'W')
				parse_texture_wall(data, tmp->line2);
			else if (*tmp->line2 == 'C' || *tmp->line2 == 'F')
				parse_texture_ceil_floor(data, tmp->line2);
		}
		tmp = tmp->next;
	}
}
