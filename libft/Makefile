# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/30 15:58:55 by jkhong            #+#    #+#              #
#    Updated: 2021/06/10 13:46:56 by jkhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(wildcard srcs/*.c)
OBJS	=	${SRCS:.c=.o}
NAME	=	libft.a
CFLAGS	=	-Wall -Wextra -Werror

.c.o:
			gcc ${CFLAGS} -c -Iincludes $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
