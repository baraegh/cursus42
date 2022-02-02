# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 13:36:07 by eel-ghan          #+#    #+#              #
#    Updated: 2022/02/02 21:00:41 by eel-ghan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c srcs/libft/libft.a srcs/operations_utiles.c srcs/p_s_check_args.c \
		srcs/quick_sort.c  srcs/radix_sort.c srcs/push_swap_utiles.c \
		srcs/sort_num.c srcs/push_swap_utiles_2.c srcs/sort_num_utiles.c

CFLAGS	=	-Wall -Wextra -Werror

CC		=	gcc

	
${NAME} :
	cd srcs && cd Libft/ && make && make clean && cd .. && cd ..
	${CC} ${CFLAGS} -o ${NAME} ${SRCS}

all: ${NAME}
	
clean:
	rm -f ${NAME}

fclean: clean
	rm -f libft/libft.a

re: fclean all 

.PHONY: all clean fclean re