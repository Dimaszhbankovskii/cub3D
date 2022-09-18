/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:58:55 by vjose             #+#    #+#             */
/*   Updated: 2022/09/18 16:58:56 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int symbol)
{
	char	*str;
	char	c;

	str = (char *)(string + ft_strlen(string));
	c = (char) symbol;
	while ((*str != c) && str > string)
		str--;
	if (*str == c)
		return (str);
	else
		return (NULL);
}
