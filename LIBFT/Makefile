# **************************************************************************** #
#                                  Makefile                                    #
# **************************************************************************** #

NAME    = libft.a

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rcs
RM      = rm -f

SRC     = atoi.c \
          bzero.c \
          isalnum.c \
          isalpha.c \
          isascii.c \
          isdigit.c \
          isprint.c \
          memchr.c \
          memcmp.c \
          memcpy.c \
          memmove.c \
          memset.c \
          strchr.c \
		  strdup.c \
          strlcat.c \
          strlcpy.c \
          strlen.c \
          strncmp.c \
		  strrchr.c \
		  strnstr.c \
          strstr.c \
          tolower.c \
          toupper.c \
		  calloc.c

OBJ     = $(SRC:.c=.o)

all: $(NAME)

# Compilation de la bibliothèque
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# Compilation des fichiers objets
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	$(RM) $(OBJ)

# Nettoyage complet (objets + bibliothèque)
fclean: clean
	$(RM) $(NAME)

# Recompile tout depuis zéro
re: fclean all

.PHONY: all clean fclean re
