#include "cub3D.h"

int	count_type_tokens(t_token **tokens, int type)
{
	t_token	*tmp;
	int		amount;

	tmp = *tokens;
	amount = 0;
	while (tmp)
	{
		if (tmp->type == type)
			amount++;
		tmp = tmp->next;
	}
	return (amount);
}

t_token	*find_token(t_token **tokens, int type)
{
	t_token	*tmp;

	tmp = *tokens;
	while (tmp)
	{
		if (tmp->type == type)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
