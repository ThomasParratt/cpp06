NAME		=	convert

SRC			=	ScalarConverter.cpp main.cpp

CC			=	c++

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

OBJ			=	$(SRC:.cpp=.o)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
			${RM} $(OBJ)

fclean: 	clean
			${RM} $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
