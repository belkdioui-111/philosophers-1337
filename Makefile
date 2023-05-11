# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/09 14:59:00 by bel-kdio          #+#    #+#              #
#    Updated: 2023/05/11 17:38:35 by bel-kdio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = philo.c ft_atoi.c check_errors_and_loading_data.c create_philo.c create_forks.c get_curr_time.c init_philo.c handling_data_rice.c
LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

CC = cc

#-fsanitize=thread

CFLAGS = -Wall -Wextra -Werror -fsanitize=thread
NAME = philo

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ) 

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)