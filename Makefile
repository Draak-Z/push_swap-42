# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmaudet <bmaudet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 14:45:20 by bmaudet           #+#    #+#              #
#    Updated: 2021/06/09 16:50:45 by bmaudet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap

NAME2 = checker

SRCS1 = lst.c parsing.c swap.c swap1.c algo.c utils.c bruteforce.c gnl.c gnl_utils.c go_algo.c refill.c utils2.c

SRCS2 = lst.c parsing.c swap.c swap1.c checker.c gnl.c gnl_utils.c utils.c

OBJS1 = ${SRCS1:.c=.o}

OBJS2 = ${SRCS2:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -c

all:	${NAME1}

bonus:	${NAME1} ${NAME2}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME1}:	${OBJS1}
			${CC} -o ${NAME1} ${OBJS1}

${NAME2}:	${OBJS2}
			${CC} -o ${NAME2} ${OBJS2}

clean:
		${RM} ${OBJS1} ${OBJS2}

fclean:		clean
			${RM} ${NAME1} ${NAME2}

rm_cheker: clean
			${RM} ${NAME2}

rm_ps: clean
			${RM} ${NAME1}
			
re:		fclean all

.PHONY: clean all fclean re rm_cheker rm_ps
