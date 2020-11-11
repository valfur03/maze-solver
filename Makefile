# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/11 15:14:26 by vfurmane          #+#    #+#              #
#    Updated: 2020/11/11 15:22:21 by vfurmane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c maze.c parse.c put.c read.c solver.c str.c
OBJS		= $(SRCS:.c=.o)
INCL		= .
NAME		= masolve
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@ -I $(INCL)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
