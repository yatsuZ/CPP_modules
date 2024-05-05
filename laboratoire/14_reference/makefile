# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 03:22:46 by yzaoui            #+#    #+#              #
#    Updated: 2024/05/05 20:29:54 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = res.out

EXEC1 = res1.out

EXEC2 = res2.out

EXEC3 = res3.out

SRC1 =	ref1.cpp

SRC2 =	ref2.cpp

SRC3 =	ref3.cpp

OBJ_PATH = obj/

OBJ1 = $(addprefix $(OBJ_PATH), $(SRC1:.cpp=.o))
OBJ2 = $(addprefix $(OBJ_PATH), $(SRC2:.cpp=.o))
OBJ3 = $(addprefix $(OBJ_PATH), $(SRC3:.cpp=.o))

all : $(OBJ_PATH) $(EXEC)

$(EXEC) : $(OBJ1) $(OBJ2) $(OBJ3)
	$(CXX) $(CXXFLAGS) -o $(EXEC1) $(OBJ1)
	$(CXX) $(CXXFLAGS) -o $(EXEC2) $(OBJ2)
	$(CXX) $(CXXFLAGS) -o $(EXEC3) $(OBJ3)

$(OBJ_PATH) :
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: ./%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_PATH)
fclean: clean
	rm -f $(EXEC1)
	rm -f $(EXEC2)
	rm -f $(EXEC3)

re: fclean all

.PHONY : all clean fclean EXEC

