# **************************************************************************** #
#                                  Makefile                                    #
# **************************************************************************** #

SRCS	=	srcs/ft_strjoin.c \
			srcs/ft_atoi.c \
			srcs/ft_bzero.c \
			srcs/ft_split.c \
			srcs/ft_strlen.c \
			srcs/ft_strncmp.c \
			srcs/ft_toupper.c \
			srcs/ft_atoi_base.c \

OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc

INCLUDE =	includes

CFLAGS	=	-Wall -Wextra -Werror -I$(INCLUDE) -c

RM		=	rm -f

NAME	=	libft.a

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

.c.o:
			$(CC) $(CFLAGS) $< -o ${<:.c=.o}

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
