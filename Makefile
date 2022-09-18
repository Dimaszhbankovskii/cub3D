NAME			=	cub3D

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra
C_MLXFLAGS		=	-I/usr/include -Imlx
MLXFLAGS		=	-Lmlx -lmlx -L/usr/lib -Imlx -lm -lz -framework OpenGL -framework AppKit
LIBRARIES		=	-L./libft -lft

LIBMLX			=	./mlx/libmlx.a

HEADER_DIR		=	includes

HEADER_MAIN		=	cub3d.h
HEADER_PARSER	=	parser.h
HEADER_KEYS		=	keycode.h
HEADER_ERROR	=	error_mess.h

HEADER			=	$(addprefix $(HEADER_DIR)/,$(HEADER_MAIN))
HEADER			+=	$(addprefix $(HEADER_DIR)/,$(HEADER_PARSER))
HEADER			+=	$(addprefix $(HEADER_DIR)/,$(HEADER_KEYS))
HEADER			+=	$(addprefix $(HEADER_DIR)/,$(HEADER_ERROR))

LIBFT			=	./libft/libft.a

SRCS_DIR			=	srcs
SRCS_DIR_PARSER		=	srcs/parser
SRCS_DIR_EXECUTOR	=	srcs/executor

SRCS_LIST		=	main.c \
					end_program.c \
					utils_1.c \
					utils_2.c

SRCS			=	$(addprefix $(SRCS_DIR)/,$(SRCS_LIST))

SRCS_LIST_PARSER	=	tokens_1.c \
						tokens_2.c \
						parse_file_to_tokens.c \
						parse_texture.c \
						parse_texture_wall.c \
						parse_texture_ceil_floor.c \
						parse_map_1.c \
						parse_map_2.c

SRCS_PARSER			=	$(addprefix $(SRCS_DIR_PARSER)/,$(SRCS_LIST_PARSER))

SRCS_LIST_EXECUTOR	=	process_cub3d.c \
						rendering_image_1.c \
						rendering_image_2.c \
						manage_keys_1.c \
						manage_keys_2.c

SRCS_EXECUTOR		=	$(addprefix $(SRCS_DIR_EXECUTOR)/,$(SRCS_LIST_EXECUTOR))

SRCS			+= $(SRCS_PARSER)
SRCS			+= $(SRCS_EXECUTOR)

OBJS_DIR		=	objs

OBJS			=	$(addprefix $(OBJS_DIR)/,$(SRCS_LIST:.c=.o))
OBJS			+=	$(addprefix $(OBJS_DIR)/,$(SRCS_LIST_PARSER:.c=.o))
OBJS			+=	$(addprefix $(OBJS_DIR)/,$(SRCS_LIST_EXECUTOR:.c=.o))

HEADER_DIR_BONUS		=	includes_bonus

HEADER_MAIN_BONUS		=	cub3d_bonus.h
HEADER_PARSER_BONUS		=	parser_bonus.h
HEADER_KEYS_BONUS		=	keycode_bonus.h
HEADER_ERROR_BONUS		=	error_mess_bonus.h

HEADER_BONUS			=	$(addprefix $(HEADER_DIR_BONUS)/,$(HEADER_MAIN_BONUS))
HEADER_BONUS			+=	$(addprefix $(HEADER_DIR_BONUS)/,$(HEADER_PARSER_BONUS))
HEADER_BONUS			+=	$(addprefix $(HEADER_DIR_BONUS)/,$(HEADER_KEYS_BONUS))
HEADER_BONUS			+=	$(addprefix $(HEADER_DIR_BONUS)/,$(HEADER_ERROR_BONUS))

SRCS_DIR_BONUS			=	srcs_bonus
SRCS_DIR_PARSER_BONUS	=	srcs_bonus/parser_bonus
SRCS_DIR_EXECUTOR_BONUS	=	srcs_bonus/executor_bonus

SRCS_LIST_BONUS		=	main_bonus.c \
						end_program_bonus.c \
						utils_1_bonus.c \
						utils_2_bonus.c

SRCS_BONUS			=	$(addprefix $(SRCS_DIR_BONUS)/,$(SRCS_LIST_BONUS))

SRCS_LIST_PARSER_BONUS	=	tokens_1_bonus.c \
							tokens_2_bonus.c \
							parse_file_to_tokens_bonus.c \
							parse_texture_bonus.c \
							parse_texture_wall_bonus.c \
							parse_texture_ceil_floor_bonus.c \
							parse_map_1_bonus.c \
							parse_map_2_bonus.c

SRCS_PARSER_BONUS			=	$(addprefix $(SRCS_DIR_PARSER_BONUS)/,$(SRCS_LIST_PARSER_BONUS))

SRCS_LIST_EXECUTOR_BONUS	=	process_cub3d_bonus.c \
								rendering_image_1_bonus.c \
								rendering_image_2_bonus.c \
								manage_keys_1_bonus.c \
								manage_keys_2_bonus.c

SRCS_EXECUTOR_BONUS			=	$(addprefix $(SRCS_DIR_EXECUTOR_BONUS)/,$(SRCS_LIST_EXECUTOR_BONUS))

SRCS_BONUS			+= $(SRCS_PARSER_BONUS)
SRCS_BONUS			+= $(SRCS_EXECUTOR_BONUS)

OBJS_DIR_BONUS		=	objs_bonus

OBJS_BONUS			=	$(addprefix $(OBJS_DIR_BONUS)/,$(SRCS_LIST_BONUS:.c=.o))
OBJS_BONUS			+=	$(addprefix $(OBJS_DIR_BONUS)/,$(SRCS_LIST_PARSER_BONUS:.c=.o))
OBJS_BONUS			+=	$(addprefix $(OBJS_DIR_BONUS)/,$(SRCS_LIST_EXECUTOR_BONUS:.c=.o))

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

$(NAME) : $(OBJS) $(LIBFT) $(LIBMLX) $(HEADER) Makefile
	@$(CC) $(OBJS) ${MLXFLAGS} -o $@ $(LIBRARIES)
	@echo "$(GREEN)Project succesfully compiled$(NORMAL)"

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c $(HEADER) Makefile
	@$(CC) $(CFLAGS) $(C_MLXFLAGS) -O3 -c $< -o $@ -I./$(HEADER_DIR)
	@echo "$(BLUE)Creating object file$(WHITE) --> $(notdir $@) --> $(GREEN)[Done]$(NORMAL)"

$(OBJS_DIR)/%.o : $(SRCS_DIR_PARSER)/%.c $(HEADER) Makefile
	@$(CC) $(CFLAGS) $(C_MLXFLAGS) -O3 -c $< -o $@ -I./$(HEADER_DIR)
	@echo "$(BLUE)Creating object file$(WHITE) --> $(notdir $@) --> $(GREEN)[Done]$(NORMAL)"

$(OBJS_DIR)/%.o : $(SRCS_DIR_EXECUTOR)/%.c $(HEADER) Makefile
	@$(CC) $(CFLAGS) $(C_MLXFLAGS) -O3 -c $< -o $@ -I./$(HEADER_DIR)
	@echo "$(BLUE)Creating object file$(WHITE) --> $(notdir $@) --> $(GREEN)[Done]$(NORMAL)"

$(OBJS_DIR) :
	@mkdir -p objs
	@echo "$(CYAN)Creating directory for objects file$(WHITE) --> $@ --> $(GREEN)[Done]$(NORMAL)"

$(LIBFT) : ./libft/Makefile ./libft/libft.h ./libft/*.c
	@make -C ./libft
	@make bonus -C ./libft
	@echo "$(CYAN)'libft' was compiled$(NORMAL)"

$(LIBMLX) :
	@make -C ./mlx
	@echo "$(CYAN)'mlx' was compiled$(NORMAL)"

bonus : $(OBJS_DIR_BONUS) $(OBJS_BONUS) $(LIBFT) $(LIBMLX) $(HEADER_BONUS) Makefile
	@$(CC) $(OBJS_BONUS) ${MLXFLAGS} -o $(NAME) $(LIBRARIES)
	@echo "$(GREEN)Project bonus succesfully compiled$(NORMAL)"

$(OBJS_DIR_BONUS)/%.o : $(SRCS_DIR_BONUS)/%.c $(HEADER_BONUS) Makefile
	@$(CC) $(CFLAGS) $(C_MLXFLAGS) -O3 -c $< -o $@ -I./$(HEADER_DIR_BONUS)
	@echo "$(BLUE)Creating object file$(WHITE) --> $(notdir $@) --> $(GREEN)[Done]$(NORMAL)"

$(OBJS_DIR_BONUS)/%.o : $(SRCS_DIR_PARSER_BONUS)/%.c $(HEADER_BONUS) Makefile
	@$(CC) $(CFLAGS) $(C_MLXFLAGS) -O3 -c $< -o $@ -I./$(HEADER_DIR_BONUS)
	@echo "$(BLUE)Creating object file$(WHITE) --> $(notdir $@) --> $(GREEN)[Done]$(NORMAL)"

$(OBJS_DIR_BONUS)/%.o : $(SRCS_DIR_EXECUTOR_BONUS)/%.c $(HEADER_BONUS) Makefile
	@$(CC) $(CFLAGS) $(C_MLXFLAGS) -O3 -c $< -o $@ -I./$(HEADER_DIR_BONUS)
	@echo "$(BLUE)Creating object file$(WHITE) --> $(notdir $@) --> $(GREEN)[Done]$(NORMAL)"

$(OBJS_DIR_BONUS) :
	@mkdir -p objs_bonus
	@echo "$(CYAN)Creating directory for objects file$(WHITE) --> $@ --> $(GREEN)[Done]$(NORMAL)"

clean :
	@make clean -C ./libft
	@make clean -C ./mlx
	@rm -rf $(OBJS_DIR)
	@rm -rf $(OBJS_DIR_BONUS)
	@echo "$(VIOLET)Removing objects files$(WHITE) --> *.o --> $(GREEN)[Done]$(NORMAL)"

fclean : clean
	@make fclean -C ./libft
	@rm -rf $(NAME)
	@echo "$(VIOLET)Removing perfoming file$(WHITE) --> $(NAME) --> $(GREEN)[Done]$(NORMAL)"

re : fclean all

.PHONY: all clean fclean re bonus