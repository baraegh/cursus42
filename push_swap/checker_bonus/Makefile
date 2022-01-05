# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 22:58:59 by eel-ghan          #+#    #+#              #
#    Updated: 2022/01/05 21:17:52 by eel-ghan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRCS = checker.c srcs/Libft/libft.a srcs/operations_utiles.c\
		 srcs/p_s_check_args.c srcs/push_swap_utiles.c srcs/operations_utiles_plus.c\
		 srcs/get_next_line/get_next_line.c srcs/get_next_line/get_next_line_utils.c

CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address

CC		=	gcc

${NAME} : 
	cd srcs/Libft/ && make && make bonus && make clean && cd ..
	${CC} ${CFLAGS} -o ${NAME} ${SRCS}

all: ${NAME}

clean:
	rm -f ${NAME}

fclean: clean
	rm -f libft/libft.a

re: fclean all 

.PHONY: all clen fclean re