# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 13:55:43 by pweinsto          #+#    #+#              #
#    Updated: 2021/12/17 17:06:22 by pweinsto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC		=	gcc

CFLAGS	=	-Werror -Wall -Wextra

SRCS	=	srcs/philo.c		\
			srcs/death_check.c	\
			srcs/dining.c		\
			srcs/helper.c		\
			srcs/init.c			\
			srcs/utils.c		\
			srcs/timestamp.c	\

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all
