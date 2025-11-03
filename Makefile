NAME = fdf
CC = cc
FLAGS = -Wall -Wextra -Werror -g3

LIBFT_DIR = libft/
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

MLX_DIR = mlx/
MLX = $(addprefix $(MLX_DIR), libmlx.a)
MLXFLAGS = -lXext -lX11 -lm -lbsd -lz


SRCS = srcs/fdf.c srcs/clean.c srcs/parse_file.c srcs/draw.c srcs/isometric.c srcs/draw_line.c srcs/paralel.c \
		srcs/draw_board.c srcs/color.c srcs/zoom.c srcs/translate.c srcs/rotate.c srcs/math.c srcs/height.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c Makefile
	$(CC) -c $(FLAGS) $< -o $@

clean_local:
	rm -rf $(OBJS)

clean: clean_local
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean_local
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
