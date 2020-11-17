# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/11 15:14:26 by vfurmane          #+#    #+#              #
#    Updated: 2020/11/17 10:43:50 by vfurmane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= args.c graphics.c main.c maze.c parse.c put.c read.c solver.c \
				str.c
G_SRCS		= $(addprefix generator/, main.c maze.c str.c)
OBJS		= $(SRCS:.c=.o)
G_OBJS		= $(G_SRCS:.c=.o)
INCL		= .
G_INCL		= ./generator
NAME		= masolve
G_NAME		= magen
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SDL_FLAGS	= $(shell pkg-config --cflags --libs sdl2)
RM			= rm -f

%.o:		%.c
			$(CC) $(CFLAGS) -c $< $(SDL_FLAGS) -o $@ -I $(INCL)

all:		$(NAME) $(G_NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(SDL_FLAGS) -o $@

$(G_NAME):	$(G_OBJS)
			$(CC) $(CFLAGS) $(G_OBJS) -o $(G_INCL)/$@

clean:
			$(RM) $(OBJS)

g_clean:
			$(RM) $(G_OBJS)

fclean:		clean g_clean
			$(RM) $(NAME) && $(RM) $(G_INCL)/$(G_NAME)

re:			fclean all

.PHONY:		all clean g_clean fclean re
