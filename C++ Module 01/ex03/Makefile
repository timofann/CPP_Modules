CC		=	c++
CFLAGS	= 	-Wall -Wextra -Werror -std=c++98
NAME	=	UnnecessaryViolence
HEADERS	=	Weapon.h HumanA.h HumanB.h
SRC		=	Weapon.cpp HumanA.cpp HumanB.cpp main.cpp
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