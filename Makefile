# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 16:13:31 by ojospeh           #+#    #+#              #
#    Updated: 2021/10/20 20:38:30 by ojospeh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRC		= so_main.c

SRC_DIR	= src
SRCS	= ${addprefix ${SRC_DIR}/, ${SRC}}

HEAD	= ${SRC_DIR}/so_long.h

LIB_DIR	= libft
LIBA	= ${LIB_DIR}/libft.a

LIB_FILES	:= $(wildcard ${LIB_DIR}/*)
LIB_LIST	:= ${notdir ${LIB_FILES}}

OBJ_DIR		= obj
OBJS		= ${SRC:%.c=${OBJ_DIR}/%.o}
DEPS		= $(OBJS:.o=.d)

INC_DIRS	= ./${LIB_DIR}/
INC_FLAG	= $(addprefix -I,$(INC_DIRS))
CPPFLAGS	= $(INC_FLAG)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

RMR		= rm -r

all:		${NAME}

${NAME}: 			${SRCS} ${HEAD} ${LIBA} ${OBJS}
			@${CC} ${CFLAGS} ${LIBA} ${OBJS} -o $@
			@echo "${NAVY} ${CC} ${CFLAGS} ${YELLOW} $(notdir ${LIBA}) \
	${PURPLE} $(notdir ${OBJS})	${RESET}  -o ${GREEN} $@ ${RESET}"

${LIBA}:			$(wildcard ${LIB_DIR}/*.c)
			@make -C libft

${OBJ_DIR}/%.o:		${SRC_DIR}/%.c
			@mkdir -p ${dir $@}
			@${CC} ${CFLAGS} ${CPPFLAGS} -c $< -o $@
			@echo "${NAVY} ${CC} ${CFLAGS} ${CPPFLAGS} -c ${RESET} $< \
	${PURPLE} -o  $(notdir $@) ${RESET}"

clean:
			${RMR} ${OBJ_DIR}
			@echo " delete ${RED} ${filter %.o,${LIB_LIST}} ${RESET}"
			@$(shell cd $(LIB_DIR); make clean)

fclean:				clean
			@echo " delete ${RED} $(notdir ${wildcard ${NAME} ${LIB_DIR}/*.a})\
			${RESET}"
			@${RM} ${NAME} debug_so
			@$(shell cd $(LIB_DIR); make fclean)

re:					fclean all

debug_so: 			${SRCS} ${HEAD} ${LIBA}
			@${CC} -g ${CFLAGS} ${CPPFLAGS} ${LIBA} ${SRCS} -o $@
			@echo "${NAVY} ${CC} -g ${CFLAGS} ${YELLOW} $(notdir ${LIBA}) \
	${PURPLE} $(notdir ${SRCS})	${RESET}  -o ${GREEN} $@ ${RESET}"


norm:
			norminette ${SRCS} ${HEAD}

.PHONY:		all clean fclean re norm


color:
		@echo "${YELLOW} ${LIBA} ${NAVY} ${CPPFLAGS}"

#COLORS
RED		= \033[0;31m
BLUE	= \033[0;34m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
PURPLE	= \033[0;35m
NAVY	= \033[0;36m
RESET	= \033[0m