# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 16:27:25 by pweinsto          #+#    #+#              #
#    Updated: 2021/12/17 17:03:59 by pweinsto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_BONUS = philo_bonus

CC		=	gcc

CFLAGS	=	-Werror -Wall -Wextra

SRCS_BONUS =	srcs_bonus/philo_bonus.c			\
				srcs_bonus/death_check_bonus.c		\
				srcs_bonus/dining_bonus.c			\
				srcs_bonus/helper_bonus.c			\
				srcs_bonus/init_bonus.c				\
				srcs_bonus/itoa_bonus.c				\
				srcs_bonus/timestamp_bonus.c		\

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

MANDATORY_OBJS	=	../philo/srcs/death_check.o	\
					../philo/srcs/dining.o		\
					../philo/srcs/helper.o		\
					../philo/srcs/init.o		\
					../philo/srcs/utils.o		\
					../philo/srcs/timestamp.o	\

bonus			:	mandatory $(NAME_BONUS)

mandatory	:
					make -C ../philo/

$(NAME_BONUS)	:	$(OBJS_BONUS)
					$(CC) $(CFLAGS) $(OBJS_BONUS) $(MANDATORY_OBJS) -o $(NAME_BONUS) 

clean_mandatory:
					make clean -C ../philo/

clean			:	clean_mandatory
					rm -f $(OBJS_BONUS)

fclean_mandatory:
					make fclean -C ../philo/

fclean			:	clean fclean_mandatory
					rm -f $(NAME_BONUS)

re				:	fclean bonus