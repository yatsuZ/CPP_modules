# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 02:45:08 by yzaoui            #+#    #+#              #
#    Updated: 2024/03/28 16:04:03 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Convention de nommage de variable


CXX = c++


CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

EXEC = res.out

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(EXEC)

re: fclean all
