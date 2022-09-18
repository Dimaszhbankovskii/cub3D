/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:58:56 by vjose             #+#    #+#             */
/*   Updated: 2022/09/18 16:58:57 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_char_in_set(char chr, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == chr)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	while (ft_char_in_set(s1[start], set) && s1[start])
		start++;
	end = ft_strlen(s1);
	while (ft_char_in_set(s1[end - 1], set) && end > start)
		end--;
	str = (char *)malloc((sizeof(*s1) * (end - start + 1)));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
