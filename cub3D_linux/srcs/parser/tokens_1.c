#include "cub3D.h"

t_token	*new_token(t_main *data)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		end_program(data, ERROR_MALLOC_TOKEN, 1);
	token->line1 = data->file.line;
	data->file.line = NULL;
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

static int	define_type_token(t_token *token)
{
	if (*token->line2 == 'N' || *token->line2 == 'S' || \
	*token->line2 == 'E' || *token->line2 == 'W' || \
	*token->line2 == 'C' || *token->line2 == 'F')
		return (TOKEN_TEXTURE);
	else if (!*token->line2)
		return (TOKEN_SEPARATOR);
	else
		return (TOKEN_MAP);
}

void	prepare_tokens(t_main *data)
{
	t_token	*token;

	token = data->tokens;
	while (token)
	{
		token->line2 = ft_strtrim(token->line1, SEP);
		if (!token->line2)
			end_program(data, ERROR_FT_STRTRIM, 1);
		token->type = define_type_token(token);
		token = token->next;
	}
}
