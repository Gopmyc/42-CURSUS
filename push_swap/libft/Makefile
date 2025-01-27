# **************************************************************************** #
#                                  Makefile                                    #
# **************************************************************************** #

NAME = libft.a

SRC = ${LIBC} ${ADDITIONAL}

SRCALL = ${LIBC} ${ADDITIONAL} ${BONUS}

OBJS = ${SRC:.c=.o}

OBJSALL = ${SRCALL:.c=.o} 

CC = cc

CFLAGS = -Wall -Werror -Wextra -I ./

AR = ar
ARFLAGS = rsc

LIBC =	src/convert/ft_atoi.c \
		src/memory/ft_bzero.c \
		src/memory/ft_calloc.c \
		src/is/ft_isalnum.c \
		src/is/ft_isalpha.c \
		src/is/ft_isascii.c \
		src/is/ft_isdigit.c \
		src/is/ft_isprint.c \
		src/is/is_number.c \
		src/memory/ft_memchr.c \
		src/memory/ft_memcmp.c \
		src/memory/ft_memcpy.c \
		src/memory/ft_memmove.c \
		src/memory/ft_memset.c \
		src/str/ft_strchr.c \
		src/str/ft_strdup.c \
		src/str/ft_strlcat.c \
		src/str/ft_strlcpy.c \
		src/str/ft_strlen.c \
		src/str/ft_strncmp.c \
		src/str/ft_strnstr.c \
		src/str/ft_strrchr.c \
		src/convert/ft_tolower.c \
		src/convert/ft_toupper.c  \
		src/convert/ft_atol.c \
		src/str/ft_strrec.c

ADDITIONAL =	src/convert/ft_itoa.c \
				src/put/ft_putchar_fd.c \
				src/put/ft_putendl_fd.c \
				src/put/ft_putnbr_fd.c \
				src/put/ft_putstr_fd.c \
				src/convert/ft_split.c \
				src/str/ft_strjoin.c \
				src/str/ft_strmapi.c \
				src/str/ft_strtrim.c \
				src/str/ft_substr.c \
				src/str/ft_striteri.c

BONUS =	src/lst/ft_lstlast_bonus.c \
		src/lst/ft_lstsize_bonus.c

.c.o:
		${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJSALL}
		${AR} ${ARFLAGS} ${NAME} ${OBJSALL}

bonus:	${OBJSALL}
		${AR} ${ARFLAGS} ${NAME} ${OBJSALL}

all: 	${NAME}

clean:	
		rm -f ${OBJSALL}

fclean:	clean;
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re bonus