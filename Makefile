# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 15:42:02 by jkhong            #+#    #+#              #
#    Updated: 2021/07/08 08:54:05 by jkhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	srcs/pipex.c		srcs/utils.c
SRCS_BONUS	=	srcs/pipex_bonus.c	srcs/utils.c
OBJS		=	${SRCS:.c=.o}
OBJS_BONUS	=	${SRCS_BONUS:.c=.o}
HEADER		=	-I ./includes -I ./libft/includes
LIB			=	-L ./libft	-l ft
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	pipex

%.o: %.c
			$(CC) $(CFLAGS) -c $(HEADER) $< -o ${<:.c=.o}

all:		$(NAME)

libft:
			make -C ./libft

clean_libft:
			make clean -C ./libft

$(NAME): 	libft $(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)

bonus:		libft $(OBJS_BONUS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS_BONUS) $(LIB)

clean:		clean_libft
			rm -f $(OBJS) $(OBJS_BONUS)

fclean:		clean
			rm -f $(NAME) ./libft/libft.a

re:			fclean all

.PHONY:		all clean fclean re libft clean_libft
