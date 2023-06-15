# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kallegre <kallegre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 12:03:07 by kortolan          #+#    #+#              #
#    Updated: 2023/06/15 17:25:19 by kallegre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC         =     gcc

CFLAGS     =     -Wall -Wextra -Werror

LIBFT    =    ft_printf/libftprintf.a

SRCS     =  main.c \
			get_next_line/get_next_line_bonus.c \
			get_next_line/get_next_line_utils_bonus.c \
											

OBJS    = $(SRCS:.c=.o)
            
NAME = minishell

all:    $(NAME)

$(NAME):    $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

$(LIBFT):
	make -C ft_printf

clean:
	make clean -C ft_printf
	rm -rf $(OBJS)

fclean: clean
	rm -rf ft_printf/libftprintf.a
	rm -rf $(NAME)

re: fclean all