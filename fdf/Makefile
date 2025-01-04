# **************************************************************************** #
#                                  Makefile                                    #
# **************************************************************************** #

NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
MLX = ./minilibx/libmlx.a
MLX_DIR = ./minilibx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lXrender -lm
SRCS =		check.c \
			debug_draw.c \
			debug.c \
			draw.c \
			events.c \
			fdf.c \
			main.c \
			memory.c \
			utils.c \
			vertices.c
OBJS = $(SRCS:.c=.o)

# Règles

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLAGS)

# Compilation de libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Compilation de minilibx
$(MLX):
	make -C $(MLX_DIR)

# Compile les fichiers .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

# Nettoyage complet
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean

# Recompile tout
re: fclean all

.PHONY: all clean fclean re