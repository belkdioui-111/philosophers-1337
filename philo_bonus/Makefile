# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/09 14:59:00 by bel-kdio          #+#    #+#              #
#    Updated: 2023/05/23 11:36:39 by bel-kdio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = philo.c ft_atoi.c check_errors_and_loading_data.c create_philo.c create_sema.c get_curr_time.c init_philo.c free_all.c action.c handling_data_rice.c
LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

CC = cc



CFLAGS = -Wall -Wextra -Werror -pthread #-g -fsanitize=thread
NAME = philo_bonus

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ) 

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)