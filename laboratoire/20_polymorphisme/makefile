# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 03:22:46 by yzaoui            #+#    #+#              #
#    Updated: 2024/05/05 21:26:45 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


EXEC = res.out

SRC =	poly1.cpp

OBJ_PATH = obj/
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.cpp=.o))


all : $(OBJ_PATH) $(EXEC)

$(EXEC) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

#mkdir -p == crée ce dossier si il nexiste pas

$(OBJ_PATH) :
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: ./%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_PATH)
fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY : all clean fclean

