CC = c++
FLAGS = -Wall -Wextra -Werror -g3 -std=c++98 -pedantic
RM = rm -rf

SRC = \
		tests.cpp\
		Account.cpp\

HPP = \
		Account.hpp\

#SRC_DIR = $(addprefix src/, $(SRC))
OBJ = ${SRC:.cpp=.o}

NAME = Test

#INCLUDES = -Iinclude/

%.o: %.cpp
	${CC} ${FLAGS} -c $< -o $@

all: ${NAME}

$(NAME): $(OBJ)
	$(CC) ${FLAGS} $(OBJ) -o $(NAME)

re: fclean all

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

.PHONY: all re clean fclean