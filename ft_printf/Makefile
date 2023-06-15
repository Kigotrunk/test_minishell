# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kallegre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 21:17:58 by kallegre          #+#    #+#              #
#    Updated: 2022/12/05 21:25:11 by kallegre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
SRCS		= ft_printf.c print_1.c print_2.c
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

.c.o:
			${CC} ${CFLAGS} -g -I includes/ -c $< -o ${<:.c=.o}

OBJS		= ${SRCS:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			make bonus -C libft
			cp libft/libft.a ./${NAME}
			ar rcs ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}
			make clean -C libft

fclean: 	clean
			${RM} ${NAME}
			${RM} libft.a
			make fclean -C libft

re:			fclean all
