# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlong <jlong@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/22 14:57:33 by jlong             #+#    #+#              #
#    Updated: 2021/07/22 15:58:09 by jlong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= ft_printf_number ft_printf_printf ft_printf_untils ft_printf

SRCS		= $(addsuffix .c, ${SRC})

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= gcc
RM			= rm -f
AR			= ar rc
RN			= ranlib

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}
			${RN} ${NAME}

all:		$(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
