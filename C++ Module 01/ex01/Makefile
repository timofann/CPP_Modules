CC		=	c++
CFLAGS	= 	-Wall -Wextra -Werror -std=c++98
NAME	=	moarBrainz
HEADERS	=	Zombie.h
SRC		=	Zombie.cpp zombieHorde.cpp main.cpp
OBJ		=	$(SRC:.cpp=.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all