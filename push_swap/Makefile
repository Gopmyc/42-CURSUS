NAME      := push_swap
CFLAGS     := -Wall -Wextra -g3
LIB	:= libft/libft.a

SRC	:=	src/main.c \
		src/utiles/utiles.c \
		src/utiles/memory.c \
		src/parse/map.c \
		src/instructions/base_instructions.c \
		src/instructions/push_stack.c \
		src/instructions/reverse_rotate_stack.c \
		src/instructions/reverse_stack.c \
		src/instructions/swap_stack.c \
		src/algorithme/radix.c \
		src/algorithme/small_algs.c \

OBJ      := $(SRC:.c=.o)

%.o:            %.c
		$(CC) $(CFLAGS) -c $< -o $@ -I include

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