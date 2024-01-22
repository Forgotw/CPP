# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsohler@student.42.fr <lsohler>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 09:20:20 by lsohler@stu       #+#    #+#              #
#    Updated: 2024/01/19 10:47:09 by lsohler@stu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
FLAGS = -Wall -Wextra -Werror -g3 -std=c++98 -pedantic
RM = rm -rf
INCLUDES = -I $(CURDIR)

SRC = \
		main.cpp\
		ClapTrap.cpp\

#SRC_DIR = $(addprefix src/, $(SRC))
OBJ = ${SRC:.cpp=.o}

NAME = ClapTrap

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