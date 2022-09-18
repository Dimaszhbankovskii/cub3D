/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:58:27 by vjose             #+#    #+#             */
/*   Updated: 2022/09/18 16:58:28 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	if (!src && !dst)
		return (NULL);
	if (dst < src)
	{
		s = (unsigned char *)src;
		d = (unsigned char *)dst;
		while (n--)
			*d++ = *s++;
	}
	else
	{
		s = (unsigned char *)src + n;
		d = (unsigned char *)dst + n;
		while (n--)
			*--d = *--s;
	}
	return (dst);
}
