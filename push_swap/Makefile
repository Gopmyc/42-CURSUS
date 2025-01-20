NAME      := push_swap
CFLAGS     := -Wall -Wextra -Werror -g3
LIB	:= libft/libft.a

SRC	:=	sources/main.c \
		sources/utiles/utiles.c \
		sources/utiles/memory.c \
		sources/parse/map.c \
		sources/instructions/base_instructions.c \
		sources/instructions/push_stack.c \
		sources/instructions/reverse_rotate_stack.c \
		sources/instructions/reverse_stack.c \
		sources/instructions/swap_stack.c \
		sources/algorithme/radix.c \
		sources/algorithme/small_algs.c \

OBJ      := $(SRC:.c=.o)

%.o:            %.c
		$(CC) $(CFLAGS) -c $< -o $@ -I includes

$(NAME):        $(OBJ) $(LIB)
		cp $(LIB) $(NAME)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

$(LIB):
		$(MAKE) -C libft

all:	$(NAME)

clean:
		$(MAKE) clean -C libft
		rm -f $(OBJ)

fclean:         clean
		rm -f $(NAME)
		rm -f $(LIB)

re:             fclean all

.PHONY:         all clean fclean re