# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchennia <pchennia@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 13:32:44 by pchennia          #+#    #+#              #
#    Updated: 2024/06/06 14:41:58 by pchennia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

B_NAME  = philo_bonus

CFILES = actions.c helper_func.c main.c routine.c

OFILES = $(CFILES:.c=.o)

INCLUDE = philo.h

CC = gcc

CFLAGS = -g3 -Wall -Werror -Wextra
		
RM = rm -rf

RED := \033[1;31m
GREEN := \033[1;32m
RESET = \033[0m

.c.o:
	@ $(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OFILES) $(INCLUDE)
	@ $(CC) $(CFLAGS) $(OFILES) -o $(NAME)
	@ echo "$(GREEN) 'philo' created!$(RESET)"

norm:
	norminette $(CFILES)
	
clean:
	@ $(RM) $(OFILES)

fclean: clean
	@ $(RM) $(NAME) 
	@ echo "$(RED) 'philo' removed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re