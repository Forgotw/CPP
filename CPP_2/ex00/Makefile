# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsohler <lsohler@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 15:42:59 by lsohler           #+#    #+#              #
#    Updated: 2024/01/14 17:31:07 by lsohler          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
FLAGS = -Wall -Wextra -Werror -g3 -std=c++98 -pedantic
RM = rm -rf
INCLUDES = -I $(CURDIR)

SRC = \
		main.cpp\
		Fixed.cpp\

#SRC_DIR = $(addprefix src/, $(SRC))
OBJ = ${SRC:.cpp=.o}

NAME = Fixed

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