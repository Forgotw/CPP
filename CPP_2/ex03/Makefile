
CC = c++
FLAGS = -Wall -Wextra -Werror -g3 -std=c++98 -pedantic
RM = rm -rf
INCLUDES = -I $(CURDIR)

SRC = \
		main.cpp\
		Fixed.cpp\
		Point.cpp\

#SRC_DIR = $(addprefix src/, $(SRC))
OBJ = ${SRC:.cpp=.o}

NAME = BSP

#INCLUDES = -Iinclude/

%.o: %.cpp
	${CC} ${FLAGS} -c $< -o $@ $(INCLUDES)

all: ${NAME}

$(NAME): $(OBJ)
	$(CC) ${FLAGS} $(OBJ) -o $(NAME) $(INCLUDES)

re: fclean all

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

.PHONY: all re clean fclean
