CC			= gcc
CFLAGS		= -Wextra -Wall
MLX_LINUX_FLAGS	= -lm -lX11 -lXext
NAME		= fdf

LIBFT_PATH	= ./libs/libft/
LIBFT		= $(LIBFT_PATH)libft.a

MLX_PATH	= ./libs/minilibx-linux/
MLX			= $(MLX_PATH)libmlx.a

SRC_PATH 	= srcs/
OBJ_PATH 	= obj/

SRC			= animate.c \
			calculate_pt.c \
			colors.c \
			gradient_theme.c \
			display.c \
			ft_hooks.c \
			ft_init.c \
			fun_themes.c \
			new_main.c \
			srs_themes.c \
			bresenham.c \
			ft_free.c \
			display_hud.c

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(LIBFT) $(MLX) $(OBJ_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_LINUX_FLAGS) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(MLX):
	make -C $(MLX_PATH)

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
