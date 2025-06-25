CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98

NAME		:= braiiiiiiinnnzzzZ

SRCS		:= main.cpp \
			   Zombie.cpp \
			   newZombie.cpp \
			   randomChump.cpp

OBJS		:= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp Zombie.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
