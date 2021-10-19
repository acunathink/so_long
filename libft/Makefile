# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/26 12:22:34 by ojospeh           #+#    #+#              #
#    Updated: 2021/10/19 16:45:28 by ojospeh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

HEAD	= libft.h

SRC		= ft_strlen.c ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c	\
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_strlcpy.c ft_strlcat.c	\
		ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c		\
		ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c		\
		ft_memcmp.c ft_calloc.c ft_strdup.c ft_bzero.c						\
																			\
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c			\
		ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c			\
		ft_putnbr_fd.c

BONUS	= ft_lstnew.c

OBJS	= ${SRC:.c=.o}

CC		:= gcc
AR		:= ar rcs
RM		:= rm -f
TEST	= ${CC} ${CFLAGS} -o $@ tests/test_$@.c -L. -lft

CFLAGS	= -Wall -Wextra -Werror


all:		$(NAME)

${NAME}:	${OBJS}
			@${AR} $@ $?
			@echo "${GREEN} ${AR} ${YELLOW} $@ ${RESET}  $?"

.c.o:		${SRC}
			@${CC} ${CFLAGS} -c $? -o ${?:.c=.o}

clean:
			@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all
			@${RM} ${OBJS}

norm:
			norminette ft_*.c

run:		fclean all fclean
			${RM} ${OBJS}

bonus:		${BONUS}

libft:		${HEAD} ${SRC} ${NAME}


strlen:		re
			${TEST}

tolower:	re
			${TEST}

toupper:	re
			${TEST}

isprint:	re
			${TEST}

isascii:	re
			${CC} ${CFLAGS} -o isascii tests/test_isascii.c -L. -lft

isalpha:	re
			${TEST}

isdigit:	re
			${TEST}

isalnum:	re
			${TEST}

strlcpy:	re
			${TEST}

strlcat:	re
			${CC} ${CFLAGS} -o strlcat tests/test_strlcat.c -L. -lft

strchr:		re
			${TEST}

strrchr:	re
			${TEST}

strnstr:	re
			${TEST}

strncmp:	re
			${TEST}

atoi:		re
			${CC} ${CFLAGS} -o atoi tests/test_atoi.c -L. -lft

bzero:		re
			${TEST}

strjoin:	re
			${TEST}

strtrim:	re
			${TEST}

split:		re
			${TEST}

itoa:		re
			${TEST} && ./itoa

putnbr_fd:	re
			${TEST}


.PHONY:		all clean fclean re norm .c.o libft



#COLORS
RED		= \033[0;31m
BLUE	= \033[0;34m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
PURPLE	= \033[0;35m
NAVY	= \033[0;36m
RESET	= \033[0m