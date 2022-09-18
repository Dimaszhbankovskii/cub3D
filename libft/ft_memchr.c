/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:58:23 by vjose             #+#    #+#             */
/*   Updated: 2022/09/18 16:58:24 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int chr, size_t n)
{
	unsigned char	*s;
	unsigned char	c;

	s = (unsigned char *) src;
	c = (unsigned char) chr;
	while (n--)
	{
		if (*s == c)
			return ((void *)s);
		s++;
	}
	return (0);
}
