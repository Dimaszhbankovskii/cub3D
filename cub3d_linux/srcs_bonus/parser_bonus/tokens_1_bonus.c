#include "cub3d_bonus.h"

t_token	*new_token(t_main *data)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		end_program(data, ERROR_MALLOC_TOKEN, 1);
	token->line1 = ft_strdup(data->file.line);

	if (data->file.line)
	{
		free (data->file.line);
		data->file.line = NULL;
	}
	token->line2 = NULL;
	token->next = NULL;
	return (token);
}

void	add_token(t_token **tokens, t_token *new)
{
	t_token	*tmp;

	if (new)
	{
		tmp = *tokens;
		if (!tmp)
			*tokens = new;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}

void	free_tokens(t_main *data)
{
	t_token	*tmp;
	t_token	*del;

	del = data->tokens;
	while (del)
	{
		tmp = del->next;
		if (del->line1)
			free (del->line1);
		if (del->line2)
			free (del->line2);
		free (del);
		del = tmp;
	}
	data->tokens = NULL;
}

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
