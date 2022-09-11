NAME			=	cub3d

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra -g
LIBRARIES		=	-L./libft -lft

HEADER_DIR		=	includes

HEADER_MAIN		=	cub3D.h
HEADER_PARSER	=	parser.h
HEADER_KEYS		=	keycode_mac.h
HEADER_ERROR	=	error_mess.h

HEADER			=	$(addprefix $(HEADER_DIR)/,$(HEADER_MAIN))
HEADER			+=	$(addprefix $(HEADER_DIR)/,$(HEADER_PARSER))
HEADER			+=	$(addprefix $(HEADER_DIR)/,$(HEADER_KEYS))
HEADER			+=	$(addprefix $(HEADER_DIR)/,$(HEADER_ERROR))

LIBFT			=	./libft/libft.a

SRCS_DIR		=	srcs
SRCS_DIR_PARSER	=	srcs/parser

SRCS_LIST		=	main.c \
					process_cub3d.c \
					init_game_cub3d.c \
					raycasting.c \
					loop_cub3d.c \
					end_program.c \
					utils.c \
					check_prog.c

SRCS			=	$(addprefix $(SRCS_DIR)/,$(SRCS_LIST))

SRCS_LIST_PARSER	=	tokens_1.c \
						tokens_2.c \
						parse_file_to_tokens.c \
						parse_texture.c \
						parse_texture_wall.c \
						parse_texture_ceil_floor.c \
						parse_map.c

SRCS_PARSER		=	$(addprefix $(SRCS_DIR_PARSER)/,$(SRCS_LIST_PARSER))

SRCS			+= $(SRCS_PARSER)

OBJS_DIR		=	objs

OBJS			=	$(addprefix $(OBJS_DIR)/,$(SRCS_LIST:.c=.o))
OBJS			+=	$(addprefix $(OBJS_DIR)/,$(SRCS_LIST_PARSER:.c=.o))

NORMAL			=	\033[0m
BOLD			=	\033[1m
UNDERLINE		=	\033[4m
BLACK			=	\033[1;30m
RED				=	\033[1;31m
GREEN			=	\033[1;32m
YELLOW			=	\033[1;33m
BLUE			=	\033[1;34m
VIOLET			=	\033[1;35m
CYAN			=	\033[1;36m
WHITE			=	\033[1;37m

all : $(OBJS_DIR) $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(HEADER) Makefile
	@$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBRARIES)
	@echo "$(GREEN)Project succesfully compiled$(NORMAL)"

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c $(HEADER) Makefile
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@ -I./$(HEADER_DIR)
	@echo "$(BLUE)Creating object file$(WHITE) --> $(notdir $@) --> $(GREEN)[Done]$(NORMAL)"

$(OBJS_DIR)/%.o : $(SRCS_DIR_PARSER)/%.c $(HEADER) Makefile
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@ -I./$(HEADER_DIR)
	@echo "$(BLUE)Creating object file$(WHITE) --> $(notdir $@) --> $(GREEN)[Done]$(NORMAL)"

$(OBJS_DIR) :
	@mkdir -p objs
	@echo "$(CYAN)Creating directory for objects file$(WHITE) --> $@ --> $(GREEN)[Done]$(NORMAL)"

$(LIBFT) : ./libft/Makefile ./libft/libft.h ./libft/*.c
	@make -C ./libft
	@make bonus -C ./libft
	@echo "$(CYAN)'libft' was compiled$(NORMAL)"

clean :
	@make clean -C ./libft
	@rm -rf $(OBJS_DIR)
	@echo "$(VIOLET)Removing objects files$(WHITE) --> *.o --> $(GREEN)[Done]$(NORMAL)"

fclean : clean
	@make fclean -C ./libft
	@rm -rf $(NAME)
	@echo "$(VIOLET)Removing perfoming file$(WHITE) --> $(NAME) --> $(GREEN)[Done]$(NORMAL)"

re : fclean all

.PHONY: all clean fclean re bonus