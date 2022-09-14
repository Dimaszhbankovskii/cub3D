#include "cub3d_bonus.h"

int	size_two_array_char(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
		i++;
	return (i);
}

char	**malloc_two_array_char(char **array)
{
	char	**res;
	int		i;

	res = (char **)malloc(sizeof(char *) * \
	(size_two_array_char(array) + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < size_two_array_char(array) + 1)
		res[i] = NULL;
	return (res);
}

void	free_two_array_char(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array && array[i])
		{
			free (array[i]);
			i++;
		}
		free (array);
	}
}

int	ft_str_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**calloc_two_array_char(int size)
{
	char	**array;
	int		i;

	array = (char **)malloc(sizeof(char *) * (size + 1));
	if (!array)
		return (NULL);
	i = -1;
	while (++i < size + 1)
		array[i] = NULL;
	return (array);
}
