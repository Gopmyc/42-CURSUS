# **************************************************************************** #
#                                  Makefile                                    #
# **************************************************************************** #

NAME = libft.a

SRCS = ${LIBC} ${ADDITIONAL}

SRCSALL = ${LIBC} ${ADDITIONAL} ${BONUS}

OBJS = ${SRCS:.c=.o}

OBJSALL = ${SRCSALL:.c=.o} 

CC = cc

CFLAGS = -Wall -Werror -Wextra -I ./

AR = ar
ARFLAGS = rsc

LIBC =	srcs/convert/ft_atoi.c \
		srcs/memory/ft_bzero.c \
		srcs/memory/ft_calloc.c \
		srcs/is/ft_isalnum.c \
		srcs/is/ft_isalpha.c \
		srcs/is/ft_isascii.c \
		srcs/is/ft_isdigit.c \
		srcs/is/ft_isprint.c \
		srcs/is/is_number.c \
		srcs/memory/ft_memchr.c \
		srcs/memory/ft_memcmp.c \
		srcs/memory/ft_memcpy.c \
		srcs/memory/ft_memmove.c \
		srcs/memory/ft_memset.c \
		srcs/str/ft_strchr.c \
		srcs/str/ft_strdup.c \
		srcs/str/ft_strlcat.c \
		srcs/str/ft_strlcpy.c \
		srcs/str/ft_strlen.c \
		srcs/str/ft_strncmp.c \
		srcs/str/ft_strnstr.c \
		srcs/str/ft_strrchr.c \
		srcs/convert/ft_tolower.c \
		srcs/convert/ft_toupper.c  \
		srcs/convert/ft_atol.c \
		srcs/str/ft_strrec.c

ADDITIONAL =	srcs/convert/ft_itoa.c \
				srcs/put/ft_putchar_fd.c \
				srcs/put/ft_putendl_fd.c \
				srcs/put/ft_putnbr_fd.c \
				srcs/put/ft_putstr_fd.c \
				srcs/convert/ft_split.c \
				srcs/str/ft_strjoin.c \
				srcs/str/ft_strmapi.c \
				srcs/str/ft_strtrim.c \
				srcs/str/ft_substr.c \
				srcs/str/ft_striteri.c

BONUS =	srcs/lst/ft_lstlast_bonus.c \
		srcs/lst/ft_lstsize_bonus.c

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