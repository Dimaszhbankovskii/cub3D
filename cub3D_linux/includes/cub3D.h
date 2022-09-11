#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "parser.h"
# include "error_mess.h"
# include "keycode_linux.h"

typedef struct s_file
{
	char	*filename;
	int		fd;
	int		ret;
	char	*line;
}	t_file;

typedef struct s_token
{
	char			*line1;
	char			*line2;
	int				type;
	struct s_token	*next;
}	t_token;

typedef struct s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_rgb;

typedef struct s_texture
{
	void			*prt;
	unsigned int	*texture_address;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	unsigned int	texture_width;
	unsigned int	texture_height;
	double			width_to_height;
}	t_texture;

typedef struct s_image
{
	void			*prt;
	unsigned int	*img_address;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}	t_image;

typedef struct s_ray
{
	double			distance;
	unsigned int	height;
	double			texture_position;
	char			dir;
}	t_ray;

typedef struct s_main
{
	t_file			file;
	t_token			*tokens;
	void			*mlx;
	void			*mlx_window;
	t_image			image;
	unsigned int	window_width;
	unsigned int	window_height;
	t_texture		textures[AMOUNT_TEXTURE];
	unsigned int	count_textures;
	t_rgb			color;
	unsigned int	ceil_color;
	unsigned int	old_ceil_color;
	unsigned int	floor_color;
	unsigned int	old_floor_color;
	unsigned int	amount_map_rows;
	unsigned int	max_map_width;
	char			**map;
	char			**rmap;
	// int				hero_pos_int_x;
	// int				hero_pos_int_y;
	double			hero_pos_x;
	double			hero_pos_y;
	double			hero_angle;
	double			vector_x;
	double			vector_y;
	float			center_ray;
	double			scale_column;
	t_ray			*rays;
}	t_main;

void	process_cub3d(t_main *data);
void	init_game_cub3d(t_main *data);
int		loop_cub3d(t_main *data);
void	raycasting(t_main *data);

void	parse_file_to_tokens(t_main *data);
void	parse_textures(t_main *data);
void	parse_texture_wall(t_main *data, char *line);
void	parse_texture_ceil_floor(t_main *data, char *line);
void	parse_map(t_main *data);


t_token	*new_token(t_main *data);
void	add_token(t_token **tokens, t_token *new);
void	free_tokens(t_main *data);
void	prepare_tokens(t_main *data);
int		count_type_tokens(t_token **tokens, int type);
t_token	*find_token(t_token **tokens, int type);

void	end_program(t_main *data, char *error_mess, int error_num);

//--------------

void	get_texture_address(t_texture *texture, t_main *data);
int		size_two_array_char(char **array);
char	**malloc_two_array_char(char **array);
void	free_two_array_char(char **array);
int		ft_str_isdigit(char *str);
char	**calloc_two_array_char(int size);

//--------------

void	print_tokens(t_main *data);
void	check_program(t_main *data);
void	print_map(t_main *data);
void	print_rmap(t_main *data);
void	print_ray(t_main *data, unsigned int ray);

#endif