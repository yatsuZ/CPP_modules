# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 00:08:18 by yzaoui            #+#    #+#              #
#    Updated: 2024/03/28 02:57:58 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


TOUT_LES_MAKE_FILES := $(shell find . -mindepth 2 -type f -name "makefile" -exec dirname {} \;)


# CMD_MAKE = make -s -C
CMD_MAKE = make -C

EXEC:
	@for dir in ${TOUT_LES_MAKE_FILES}; do \
		${CMD_MAKE} $$dir; \
	done

clean:
	@for dir in ${TOUT_LES_MAKE_FILES}; do \
		${CMD_MAKE} $$dir clean; \
	done

fclean:
	@for dir in ${TOUT_LES_MAKE_FILES}; do \
		${CMD_MAKE} $$dir fclean; \
	done
