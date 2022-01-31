# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 13:36:07 by eel-ghan          #+#    #+#              #
#    Updated: 2022/01/31 20:31:46 by eel-ghan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c libft/libft.a operations_utiles.c p_s_check_args.c \
		quick_sort.c  radix_sort.c push_swap_utiles.c sort_five_num.c


CFLAGS	=	-Wall -Wextra -Werror

CC		=	gcc

	
${NAME} : Libft
	cd libft/ && make && make clean && cd ..
	${CC} ${CFLAGS} -o ${NAME} ${SRCS}

all: ${NAME}
	
clean:
	rm -f ${NAME}

fclean: clean
	rm -f libft/libft.a

re: fclean all 

.PHONY: all clean fclean re