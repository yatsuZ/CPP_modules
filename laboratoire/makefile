# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 00:08:18 by yzaoui            #+#    #+#              #
#    Updated: 2024/05/10 13:05:20 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DARK_BLUE	= \033[0;34m
BLUE		= \033[0;36m
GREEN		= \033[0;32m
RED			= \033[0;31m
YELLOW		= \033[0;33m
NO_COLOR	= \033[m


TOUT_LES_MAKE_FILES := $(shell find . -mindepth 2 -type f -name "makefile" -exec dirname {} \; | sort)

CIBLE_MAKE = $(filter-out all, $(MAKECMDGOALS))

ifeq ($(CIBLE_MAKE), )
	CIBLE_MAKE_MSG := all
else
	CIBLE_MAKE_MSG := $(CIBLE_MAKE)
endif


CMD_MAKE = make -s -C
# CMD_MAKE = make -C
NUM_MAKEFILES := $(words $(TOUT_LES_MAKE_FILES))
CURRENT_MAKEFILE = 0


define print_execution
	echo "	- Execution Makefile du dossier $(BLUE) $(1) $(NO_COLOR)"
endef

define print_finished
	echo "$(DARK_BLUE)FIN D'EXECUTION$(NO_COLOR)"
endef

define print_progress_bar
	if [ $1 -lt $$(($2/2)) ]; then \
		echo -n "${YELLOW}"; \
	elif [ $1 -eq $2 ]; then \
		echo -n ""; \
	else \
		echo -n "${DARK_BLUE}"; \
	fi; \
	echo -n "["; \
	progress=0; \
	while [ $$progress -lt 10 ]; do \
		if [ $$progress -lt $$(($1*10/$2)) ]; then \
			echo -n "#"; \
		else \
			echo -n " "; \
		fi; \
		progress=$$((progress+1)); \
	done; \
	echo -n "]"; \
	echo -n "${NO_COLOR}"; \
	printf "[$$(($1*100/$2))%%] $$(($1))/$2\n" \\
endef

all:
	@echo "Cible executer = $(GREEN) $(CIBLE_MAKE_MSG) $(NO_COLOR)"
	@CURRENT_MAKEFILE=0; \
	for dir in ${TOUT_LES_MAKE_FILES}; do \
		$(call print_execution,$$dir); \
		$(call print_progress_bar, $${CURRENT_MAKEFILE} ,$(NUM_MAKEFILES)); \
		make -s -C $${dir} ${CIBLE_MAKE_MSG}; \
		CURRENT_MAKEFILE=$$((CURRENT_MAKEFILE+1)); \
		sleep 0.1; \
		printf "\033[A\033[K"; \
	done; \
	$(call print_finished); \
	$(call print_progress_bar, $${CURRENT_MAKEFILE} ,$(NUM_MAKEFILES))


# Pareille mais sans utilise de ft
# all:
# 	@echo "Cible executer = $(GREEN) $(CIBLE_MAKE_MSG) $(NO_COLOR)"
# 	@CURRENT_MAKEFILE=0; \
# 	for dir in ${TOUT_LES_MAKE_FILES}; do \
# 		echo "	- Execution Makefile du dossier $(BLUE) $$dir $(NO_COLOR) "; \
# 		echo -n "["; \
# 		progress=0; \
# 		while [ $$progress -lt 10 ]; do \
# 			if [ $$progress -lt $$((CURRENT_MAKEFILE*10/$(NUM_MAKEFILES))) ]; then \
# 				echo -n "#"; \
# 			else \
# 				echo -n " "; \
# 			fi; \
# 			progress=$$((progress+1)); \
# 		done; \
# 		echo -n "]"; \
# 		echo -n " $$((CURRENT_MAKEFILE*100/$(NUM_MAKEFILES)))% $$((CURRENT_MAKEFILE+1))/$(NUM_MAKEFILES)"; \
# 		echo ; \
# 		sleep 0.5; \
# 		printf "\033[A"; \
# 		printf "\033[K"; \
# 		CURRENT_MAKEFILE=$$((CURRENT_MAKEFILE+1)); \
# 	done; \
# 	echo "$(DARK_BLUE)FIN D'EXECUTION$(NO_COLOR)"; \
# 	progress=0; \
# 	echo -n "["; \
# 	while [ $$progress -lt 10 ]; do \
# 		if [ $$progress -lt $$((CURRENT_MAKEFILE*10/$(NUM_MAKEFILES))) ]; then \
# 			echo -n "#"; \
# 		else \
# 			echo -n " "; \
# 		fi; \
# 		progress=$$((progress+1)); \
# 	done; \
# 	echo -n "]"; \
# 	echo -n "[$$((CURRENT_MAKEFILE*100/$(NUM_MAKEFILES)))%] $$((CURRENT_MAKEFILE))/$(NUM_MAKEFILES)"


fclean : all

clean : all

re : all
