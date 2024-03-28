# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 18:21:13 by yzaoui            #+#    #+#              #
#    Updated: 2024/03/28 16:03:49 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all : res.out

main.o : main.cpp
	c++ -Wall -Wextra -Werror -o main.o -c main.cpp

res.out : main.o
	c++ -Wall -Wextra -Werror -o res.out main.o

clean:
	rm -f main.o

fclean: clean
	rm -f res.out

re: fclean all