#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <mlx.h>
# include <math.h>
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

typedef struct s_image
{
	void	*prt;
	char	*address;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_mlx
{
	void	*prt;
	void	*win;
	t_image	img;
}	t_mlx;

typedef struct s_token
{
	char			*line1;
	char			*line2;
	int				type;
	struct s_token	*next;
}	t_token;

typedef struct s_texture
{
	void	*prt;
	int		*address;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_texture;

typedef struct s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_rgb;

typedef struct s_map
{
	char	**p;
	char	**pr;
	int		height;
	int		width;
	int		x;
	int		y;
}	t_map;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_hero
{
	t_point	pos;
	t_point	dir;
}	t_hero;

typedef struct s_ray
{
	t_point	dir;
	t_point	delta;
	t_point	side;
	int		i;
	int		step_x;
	int		step_y;
	int		intersect_y;
}	t_ray;

typedef struct s_wall
{
	int		height;
	int		top;
	int		x;
	double	y;
	double	distance;
}	t_wall;

typedef struct s_main
{
	t_file			file;
	t_mlx			mlx;
	t_token			*tokens;
	t_texture		textures[WALL_TEXTURE];
	unsigned int	count_textures;
	t_rgb			color;
	unsigned int	ceil_color;
	unsigned int	floor_color;
	t_map			map;
	t_hero			hero;
	t_point			plane;
	t_ray			ray;
	t_wall			wall;
}	t_main;

void	process_cub3d(t_main *data);

void	parse_file_to_tokens(t_main *data);
void	parse_textures(t_main *data);
void	parse_texture_wall(t_main *data, char *line);
void	parse_texture_ceil_floor(t_main *data, char *line);
void	parse_map(t_main *data);
void	check_map_borders(t_main *data);
void	update_rmap(t_main *data);

void	rendering_image(t_main *data);
void	set_color_ceil_floor(t_main *data);
void	define_wall(t_main *data);
void	define_wall_x(t_main *data);
void	rendering_wall(t_main *data);
int 	press_key(int keycode, t_main *data);
void	rotate_review_right(t_main *data);
void	rotate_review_left(t_main *data);
int		close_window(t_main *data);

t_token	*new_token(t_main *data);
void	add_token(t_token **tokens, t_token *new);
void	free_tokens(t_main *data);
void	prepare_tokens(t_main *data);
int		count_type_tokens(t_token **tokens, int type);
t_token	*find_token(t_token **tokens, int type);

void	end_program(t_main *data, char *error_mess, int error_num);

void	get_texture_address(t_texture *texture, t_main *data);
int		size_two_array_char(char **array);
char	**malloc_two_array_char(char **array);
void	free_two_array_char(char **array);
int		ft_str_isdigit(char *str);
char	**calloc_two_array_char(int size);
t_point	set_point(double x, double y);
void	my_mlx_pixel_put(t_main *data, int x, int y, unsigned int color);

#endif