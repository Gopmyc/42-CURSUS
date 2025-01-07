NAME = libft.a

LIBC =    ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
        ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
        ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
        ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
        ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c 

ADDITIONAL =    ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
                ft_strmapi.c ft_strtrim.c ft_strjoin.c ft_substr.c ft_striteri.c ft_split.c 

BONUS =    ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
        ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
        ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c


SRC_DIR = srcs
INC_DIR = includes

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ${LIBC} ${ADDITIONAL}
OBJ = $(SRC:.c=.o)


%.o : %.c
	$(CC) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	@echo "Library $(NAME) created."

# $(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/libft.h
# 	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	@echo "Object files removed."

fclean: clean
	rm -f $(NAME)
	@echo "\nLibrary $(NAME) removed."

re: fclean all

.PHONY: all clean fclean re