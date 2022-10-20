# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 11:14:47 by whamoumi          #+#    #+#              #
#    Updated: 2021/06/11 14:33:35 by whamoumi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME2		=	serveur
NAME1		=	client


SRCS1		=	minitalk_client1.c
SRCS2		=	minitalk_serveur1.c minitalk_serveur2.c  minitalk_serveur3.c \

OBJS1		=	${SRCS1:.c=.o}
OBJS2		=	${SRCS2:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

all:			${NAME2} ${NAME1}

$(NAME1):		${OBJS1}
				${CC} ${CFLAGS} ${OBJS1} -o ${NAME1}

$(NAME2):		${OBJS2}
				${CC} ${CFLAGS} ${OBJS2} -o ${NAME2}
clean:
				${RM}  ${OBJS2}  ${OBJS1}

fclean:			clean
				${RM} ${NAME2} ${NAME1}

re:				fclean all
