NAME = libftprintf.a

SRCS = ft_printf.c ft_put.c

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar -rc

RM = rm -f

${NAME} :	${OBJS}
			${AR} $@ $^

all :		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
