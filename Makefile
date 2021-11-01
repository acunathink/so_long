# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 16:13:31 by ojospeh           #+#    #+#              #
#    Updated: 2021/11/01 16:14:51 by ojospeh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
NAME_B	=	so_long_bonus

SRC		=	so_main.c get_next_line_utils.c get_next_line.c so_mapcheck.c \
			so_long.c so_moving.c

SRC_B	=	so_main_bonus.c get_next_line_utils.c get_next_line.c \
			so_mapcheck_bonus.c so_long_bonus.c so_moving_bonus.c

SRC_DIR	=	src
SRCS	=	${addprefix ${SRC_DIR}/, ${SRC}}
SRCS_B	=	${addprefix ${SRC_DIR}/bonus/, ${SRC_B}}

HEAD_B	:=	${SRC_DIR}/bonus/so_long_bonus.h
HEAD	:=	${SRC_DIR}/so_long.h

LIB_DIR	=	libft
LIB_MLX	=	mlx
LIBA	=	${LIB_DIR}/libft.a

LIB_FILES	:= $(wildcard ${LIB_DIR}/*)
LIB_LIST	:= ${notdir ${LIB_FILES}}

OBJ_DIR		= obj
OBJS		= ${SRC:%.c=${OBJ_DIR}/%.o}
OBJS_B		= ${SRC_B:%.c=${OBJ_DIR}/%.o}
DEPS		= $(OBJS:.o=.d)
DEPS_B		= $(OBJS_B:.o=.d)

INC_DIRS	= ./${LIB_DIR}/
INC_FLAG	= $(addprefix -I,$(INC_DIRS))
CPPFLAGS	= $(INC_FLAG)
MLX_FLAGS	= -lmlx -framework OpenGL -framework AppKit
#MLX_FLAGS	= -lmlx -lXext -lX11

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

RMR		= rm -r

all:		${NAME} $(NAME_B)

${NAME}: 			${SRCS} ${HEAD} ${LIBA} ${OBJS}
			@${CC} ${CFLAGS} ${MLX_FLAGS} ${LIBA} ${OBJS} -o $@
			@echo "${NAVY} ${CC} ${CFLAGS} ${YELLOW} $(notdir ${LIBA}) \
	${BLUE} ${MLX_FLAGS} \
	${PURPLE} $(notdir ${OBJS})	${RESET}  -o ${GREEN} $@ ${RESET}"

${LIBA}:			$(wildcard ${LIB_DIR}/*.c)
			@make -C libft

${OBJ_DIR}/%.o:		${SRC_DIR}/%.c ${HEAD}
			@mkdir -p ${dir $@}
			@${CC} ${CFLAGS} ${CPPFLAGS} -c $< -o $@
			@echo "${NAVY} ${CC} ${CFLAGS} ${CPPFLAGS} -c ${RESET} $< \
	${PURPLE} -o  $(notdir $@) ${RESET}"

bonus:				$(NAME_B)

${HEAD_B}:
			HEAD=${HEAD_B}

${NAME_B}: 			${HEAD_B} ${SRCS_B} ${LIBA} ${OBJS_B}
			@${CC} ${CFLAGS} ${MLX_FLAGS} ${LIBA} ${OBJS_B} -o $@
			@echo "${NAVY} ${CC} ${CFLAGS} ${YELLOW} $(notdir ${LIBA}) \
	${BLUE} ${MLX_FLAGS} \
	${PURPLE} $(notdir ${OBJS})	${RESET}  -o ${GREEN} $@ ${RESET}"
			
${OBJ_DIR}/%.o:		${SRC_DIR}/%.c ${HEAD}
			@mkdir -p ${dir $@}
			@${CC} ${CFLAGS} ${CPPFLAGS} -c $< -o $@
			@echo "${NAVY} ${CC} ${CFLAGS} ${CPPFLAGS} -c ${RESET} $< \
	${PURPLE} -o  $(notdir $@) ${RESET}"

${OBJ_DIR}/%.o:		${SRC_DIR}/bonus/%.c ${HEAD_B}
			@mkdir -p ${dir $@}
			@${CC} ${CFLAGS} ${CPPFLAGS} -c $< -o $@
			@echo "${NAVY} ${CC} ${CFLAGS} ${CPPFLAGS} -c ${RESET} $< \
	${PURPLE} -o  $(notdir $@) ${RESET}"

.SILENT:

clean:
			-@${RMR}  ${OBJ_DIR} 
			@echo " delete ${RED} ${filter %.o,${LIB_LIST}} ${RESET}"
			@$(shell cd $(LIB_DIR); make clean)

fclean:				clean
			@echo " delete ${RED} $(notdir ${wildcard ${NAME} ${LIB_DIR}/*.a \
			${NAME_B} debug_so}) ${RESET}"
			@${RM} ${NAME} debug_so ${NAME_B}
			@$(shell cd $(LIB_DIR); make fclean)

re:					fclean all

debug_so: 			${SRCS} ${HEAD} ${LIBA}
			@${CC} -g ${CFLAGS} ${CPPFLAGS} ${MLX_FLAGS} ${LIBA} ${SRCS} -o $@
			@echo "${NAVY} ${CC} -g ${CFLAGS} ${YELLOW} $(notdir ${LIBA}) \
	${PURPLE} $(notdir ${SRCS})	${RESET}  -o ${GREEN} $@ ${RESET}"


norm:
			norminette ${SRCS} ${HEAD} ${HEAD_B} ${SRCS_B}

norme:
			@make -i norme

ne:		
			norminette | grep Error


.PHONY:		all clean fclean re norm bonus color

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