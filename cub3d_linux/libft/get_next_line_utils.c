#include "libft.h"

int	ft_init(char **buffer, ssize_t *read_bytes)
{
	*buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buffer)
		return (0);
	*read_bytes = 1;
	return (1);
}

int	ft_free(int read_bytes, char **buffer, char **str)
{
	if (*str && !**str)
	{
		free (*str);
		*str = NULL;
	}
	if (*buffer)
	{
		free (*buffer);
		*buffer = NULL;
	}
	if (read_bytes < 0)
		return (-1);
	else if (!read_bytes)
		return (0);
	else
		return (1);
}
