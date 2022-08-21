CC		=	c++
CFLAGS	= 	-Wall -Wextra -Werror -std=c++98 -Wshadow
NAME	=	iDontWantToSetTheWorldOnFire
HEADER	=	Animal.hpp Dog.hpp Cat.hpp Brain.hpp
SRC		=	Animal.cpp Dog.cpp Cat.cpp Brain.cpp main.cpp
OBJ		=	$(SRC:.cpp=.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all