# **************************************************************************** #
#                                  Makefile                                    #
# **************************************************************************** #

NAME		=	fdf
LIBFT		=	libft/
GNL			=	libft/get_next_line/
GC			=	libft/gc/
MLX			=	minilibx/
LIBFT_A		=	$(addprefix $(LIBFT), libft.a)
GNL_A		=	$(addprefix $(GNL), libgnl.a)
GC_A		=	$(addprefix $(GC), libgc.a)
MLX_A		=	$(addprefix $(MLX), libmlx.a)

CC			=	cc
INCLUDE 	=	includes
CFLAGS		=	-Wall -Wextra -Werror -I$(INCLUDE)
RM			=	rm -f

SRCS		=	srcs/main.c \
				srcs/data/map.c \
				srcs/draw/draw_main.c \
				srcs/draw/draw_line.c \
				srcs/inputs/hooks.c \
				srcs/inputs/keys.c \
				srcs/maths/maths_utiles.c \
				srcs/maths/maths_matrices.c \
				srcs/utils.c \

OBJS		=	$(SRCS:%.c=%.o)

all:			$(NAME)

$(NAME):		$(OBJS) $(LIBFT_A) $(GNL_A) $(GC_A) $(MLX_A)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -L$(GNL) -lgnl -L$(GC) -lgc -L$(MLX) -lmlx -lX11 -lXext -lXrender -lm -o $(NAME)
	@echo "L'exécutable \033[0;32mfdf\033[0m a été généré."

$(LIBFT_A):
	@$(MAKE) -s -C $(LIBFT)
	@echo "Libft compilée."

$(GNL_A):
	@$(MAKE) -s -C $(GNL)
	@echo "Get Next Line compilée."

$(GC_A):
	@$(MAKE) -s -C $(GC)
	@echo "Garbage Collector compilé."

$(MLX_A):
	@$(MAKE) -s -C $(MLX)
	@echo "Minilibx compilée."

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	@echo "Compilation de $<."

localclean:
	@$(RM) $(OBJS)
	@echo "Fichiers objets supprimés."

clean:			localclean
	@$(MAKE) clean -s -C $(LIBFT)
	@echo "Libft nettoyée."
	@$(MAKE) clean -s -C $(GNL)
	@echo "Get Next Line nettoyée."
	@$(MAKE) clean -s -C $(GC)
	@echo "Garbage Collector nettoyé."
	@$(MAKE) clean -s -C $(MLX)
	@echo "Minilibx nettoyée."

fclean:			localclean
	@$(MAKE) fclean -s -C $(LIBFT)
	@echo "Libft nettoyée."
	@$(MAKE) fclean -s -C $(GNL)
	@echo "Get Next Line nettoyée."
	@$(MAKE) fclean -s -C $(GC)
	@echo "Garbage Collector nettoyé."
	@$(MAKE) clean -s -C $(MLX)
	@echo "Minilibx nettoyée."
	@$(RM) $(NAME)
	@echo "Exécutable supprimé."

re:				fclean all

.PHONY:			all clean fclean re localclean bonus
