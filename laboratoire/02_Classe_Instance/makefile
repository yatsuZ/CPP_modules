# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 02:45:08 by yzaoui            #+#    #+#              #
#    Updated: 2024/03/28 16:03:57 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Convention de nommage de variable

# CC == compilateur de C / CXX == compilateur c++

CXX = c++

# CFLAGS == flags de C / CXXFLAGS == flags de c++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

EXEC = res.out

# SRC = main.cpp Sample.class.cpp
# OBJ = main.o Sample.class.o
# ou
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)# on prend la varible SRC et tout les fichier .cpp devienne des fichier .o
all : $(EXEC)

# ici $@ == $(EXEC) == res.out
$(EXEC) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^
#ou
#	$(CXX) $(CXXFLAGS) -o $@ $^
%.o : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(EXEC)

re: fclean all

# Variable spécifique

# $@ nom cible
# $< nom de la premiere dépendance
# $^ liste dépendance
# $? liste dépendance plus récentes que la cible
# $* nom fichier, sans exentsion