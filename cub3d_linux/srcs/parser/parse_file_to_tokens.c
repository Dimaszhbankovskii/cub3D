#include "cub3d.h"

static void	read_file(t_main *data)
{
	data->file.ret = get_next_line(data->file.fd, &data->file.line);
	if (data->file.ret < 0)
		end_program(data, ERROR_GNL, 1);
	while (data->file.line)
	{
		if (data->file.line[ft_strlen(data->file.line) - 1] == '\n')
			data->file.line[ft_strlen(data->file.line) - 1] = '\0';
		add_token(&data->tokens, new_token(data));
		data->file.ret = get_next_line(data->file.fd, &data->file.line);
		if (data->file.ret < 0)
			end_program(data, ERROR_GNL, 1);
	}
	if (!data->tokens)
		end_program(data, ERROR_FILE_EMPTY, 1);
}

static void	texture_before_map(t_main *data)
{
	t_token	*tmp;
	int		count_texture;

	tmp = data->tokens;
	count_texture = 0;
	while (tmp)
	{
		if (tmp->type == TOKEN_TEXTURE)
			count_texture++;
		else if (tmp->type == TOKEN_MAP && count_texture != ALL_TEXTURE)
			end_program(data, ERROR_TEXTURE_BEFORE_MAP, 1);
		else if (tmp->type == TOKEN_MAP && count_texture == ALL_TEXTURE)
			return ;
		tmp = tmp->next;
	}
}

static void	check_map_is_single(t_main *data)
{
	t_token	*tmp;

	tmp = find_token(&data->tokens, TOKEN_MAP);
	while (tmp && tmp->type == TOKEN_MAP)
		tmp = tmp->next;
	if (!tmp)
		return ;
	while (tmp)
	{
		if (tmp->type == TOKEN_MAP)
			end_program(data, ERROR_MAP_IS_SINGLE, 1);
		tmp = tmp->next;
	}
}

void	parse_file_to_tokens(t_main *data)
{
	read_file(data);
	prepare_tokens(data);
	if (count_type_tokens(&data->tokens, TOKEN_TEXTURE) != 6)
		end_program(data, ERROR_AMOUNT_TEXTURE, 1);
	if (count_type_tokens(&data->tokens, TOKEN_MAP) < 3)
		end_program(data, ERROR_MIN_MAP, 1);
	texture_before_map(data);
	check_map_is_single(data);
}
