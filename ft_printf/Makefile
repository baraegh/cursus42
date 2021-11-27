NAME = libftprintf.a

SRCS = ft_printf.c 

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar -rc

RM = rn -f

${NAME} :	${OBJS}
			${AR} $@ $^

all :		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all bonus

.PHONY:		all clean fclean re
