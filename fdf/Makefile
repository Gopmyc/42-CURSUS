# **************************************************************************** #
#                                  Makefile                                    #
# **************************************************************************** #

NAME		=	fdf
LIBFT		=	libft/
GNL			=	get_next_line/
MLX			=	minilibx/
LIBFT_A		=	$(addprefix $(LIBFT), libft.a)
GNL_A		=	$(addprefix $(GNL), libgnl.a)
MLX_A		=	$(addprefix $(MLX), libmlx.a)

CC			=	cc
INCLUDE 	=	includes
CFLAGS		=	-Wall -Wextra -Werror -I$(INCLUDE)
RM			=	rm -f
SRCS		=	fdf.c \
				srcs/alg_utils.c \
				srcs/controls.c \
				srcs/mouse.c \
				srcs/keyboard.c \
				srcs/draw.c \
				srcs/line_alg.c \
				srcs/project.c \
				srcs/parse_map.c \
				srcs/utils.c \

OBJS		=	$(SRCS:%.c=%.o)

# Règle principale pour générer l'exécutable
all:			$(NAME)

$(NAME):		$(OBJS) $(LIBFT_A) $(GNL_A) $(MLX_A)
				@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -L$(GNL) -lgnl -L$(MLX) -lmlx -lX11 -lXext -lXrender -lm -o $(NAME)
				@echo "L'exécutable \033[0;32mfdf\033[0m a été généré."

# Compilation de libft
$(LIBFT_A):
				@$(MAKE) -s -C $(LIBFT)
				@echo "Libft compilée."

# Compilation de get_next_line
$(GNL_A):
				@$(MAKE) -s -C $(GNL)
				@echo "Get Next Line compilée."

# Compilation de minilibx (Linux)
$(MLX_A):
				@$(MAKE) -s -C $(MLX)
				@echo "Minilibx compilée."

# Règle pour compiler les fichiers .c en .o
.c.o:
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
				@echo "Compilation de $<."

# Nettoyage des fichiers objets
localclean:
				@$(RM) $(OBJS)
				@echo "Fichiers objets supprimés."

# Nettoyage des fichiers objets et des bibliothèques
clean:			localclean
				@$(MAKE) clean -s -C $(LIBFT)
				@echo "Libft nettoyée."
				@$(MAKE) clean -s -C $(GNL)
				@echo "Get Next Line nettoyée."
				@$(MAKE) clean -s -C $(MLX)
				@echo "Minilibx nettoyée."

# Nettoyage complet : objets, bibliothèques et exécutable
fclean:			localclean
				@$(MAKE) fclean -s -C $(LIBFT)
				@echo "Libft nettoyée."
				@$(MAKE) fclean -s -C $(GNL)
				@echo "Get Next Line nettoyée."
				@$(MAKE) clean -s -C $(MLX)
				@echo "Minilibx nettoyée."
				@$(RM) $(NAME)
				@echo "Exécutable supprimé."

# Recompilation complète
re:				fclean all

# Déclarer ces cibles comme "non des fichiers"
.PHONY:			all clean fclean re localclean bonus
