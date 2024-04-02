# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 22:08:32 by yzaoui            #+#    #+#              #
#    Updated: 2024/04/01 19:34:57 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean val test 

############### OBJ de Module 00 exo 01

EX01_FILES =	main.cpp utils.cpp Contact.cpp PhoneBook.cpp
OBJ_PATH  = obj/
PROG_OBJ = ${addprefix ${OBJ_PATH}, ${EX01_FILES:.cpp=.o}}

############### ligne de commande

RM = rm -rf
CC = c++
C_FLAGS = -std=c++98 -g3 -Wall -Wextra -Werror -g

PROGRAM_NAME = Simulation_PhoneBook

############### COMMANDE OBLIGATOIRE

all: $(OBJ_PATH) ${PROGRAM_NAME}

${PROGRAM_NAME}: ${PROG_OBJ}
	$(CC) $(C_FLAGS) ${PROG_OBJ} -o ${PROGRAM_NAME}

$(OBJ_PATH)%.o: %.cpp
	$(CC) $(C_FLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

clean:
	$(RM) $(OBJ_PATH)

fclean: clean
	$(RM) ${PROGRAM_NAME}

re: fclean all

test: all
	./${PROGRAM_NAME}

val: all
	valgrind ./${PROGRAM_NAME}