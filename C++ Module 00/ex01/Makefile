CC				=	c++
CFLAGS			= 	-Wall -Wextra -Werror -std=c++98
NAME			=	phonebook
HEADERS			=	Contact.h PhoneBook.h table_cell.h
SRC				=	Contact.cpp PhoneBook.cpp table_cell.cpp main.cpp
OBJ				=	$(SRC:.cpp=.o)

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