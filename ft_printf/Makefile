NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC =	ft_printf_utils.c \
		ft_printf_handle.c \
    	ft_printf.c

OBJ = $(SRC:.c=.o)

RM = rm -f
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	@echo "Compilation de $(NAME) terminée."

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	@echo "Fichiers objets supprimés."

fclean: clean
	$(RM) $(NAME)
	@echo "La bibliothèque $(NAME) et les fichiers objets ont été supprimés."

re: fclean all

.PHONY: all clean fclean re
