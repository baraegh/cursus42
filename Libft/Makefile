# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 14:04:23 by eel-ghan          #+#    #+#              #
#    Updated: 2021/11/14 13:19:15 by eel-ghan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SRCS	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
# 			ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
# 			ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
# 			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
# 			ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

# SRCSBN	=	 ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
# 			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

# OBJS	=	${SRCS:.c=.o}

# OBJSBN	=	${SRCSBN:.c=.o}

# NAME 	=	run

# CC 		=	cc ${CFLAGS}

# RM 		=	rm -f

# CFLAGS	=	-Wall -Werror -Wextra

# AR 		=	ar rc

# LIBNAME	=	libft.a


# ${NAME}:	${OBJS}
# 			${CC} -o ${NAME} ${OBJS}

# bonus:		${OBJSBN}
# 			${CC} -o ${NAME} ${OBJSBN}
# 			${AR} ${LIBNAME} ${OBJSBN}

# all: 		${NAME} bonus
# 			${AR} ${LIBNAME} ${OBJS}

# cleanlib:
# 			${RM} ${LIBNAME}			

# clean:
# 			${RM} ${OBJS}
# 			${RM} ${OBJSBN}

# fclean:		clean
# 			${RM} ${NAME}

# re:			fclean all

# .PHONY:		all clean fclean re



SRCS	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJS	=	$(BONUS:.c=.o)

NAME	=	libft.a
OBJS	=	*.o
rm		=	rm -f
FLAGS	=	-Wall -Wextra -Werror

${NAME}:
	gcc ${FLAGS} -c $(SRCS)
	ar -rcs $@ $(OBJS)

all:	${NAME}

bonus:	$(OBJS) $(BONUS_OBJS)
	gcc ${FLAGS} -c $(SRCS) $(BONUS)
	ar -rcs ${NAME} $^

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re