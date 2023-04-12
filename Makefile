# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/09 14:59:00 by bel-kdio          #+#    #+#              #
#    Updated: 2023/04/09 22:14:47 by bel-kdio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = philo.c ft_atoi.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ) 

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)