# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 18:21:13 by yzaoui            #+#    #+#              #
#    Updated: 2024/03/26 18:50:00 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = res.out

FILE = main.cpp

CC = c++

OBJS = $(FILE:.cpp=.o)

all : $(NAME)

$(NAME):
	$(CC) $(FILE)

fclean:
	rm -f a.out

re : fclean all

.PHONY: all re fclean