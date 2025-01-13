NAME      := push_swap
CFLAGS     := -Wall -Wextra -Werror -g3
LIB	:= libft/libft.a

SRC	:=	srcs/main.c \
		srcs/utiles/utiles.c \
		srcs/utiles/memory.c \
		srcs/parse/map.c \
		srcs/algs/instructions.c \
		srcs/algs/radix.c \
		srcs/algs/small_algs.c \

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