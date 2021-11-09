# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szawi <szawi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 13:35:43 by szawi             #+#    #+#              #
#    Updated: 2021/11/09 13:35:43 by szawi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

#--------------------------------- SOURCES ------------------------------------

UTILS_SRC = ft_utils.c
UTILS_OBJS = $(UTILS_SRC:.c=.o)

SERVER_SRC = ft_server.c
SERVER_OBJS = $(SERVER_SRC:.c=.o)

CLIENT_SRC = ft_client.c
CLIENT_OBJS = $(CLIENT_SRC:.c=.o)

#--------------------------------- CONSTANT -----------------------------------

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = server
SERVER_NAME = server
CLIENT_NAME = client

#----------------------------------- RULES ------------------------------------

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all:	$(UTILS_OBJS) $(SERVER_OBJS) $(CLIENT_OBJS) $(NAME)

$(NAME):	$(UTILS_OBJS) $(SERVER_OBJS) $(CLIENT_OBJS) ft_server ft_client

ft_server:
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(UTILS_OBJS) -o $(SERVER_NAME)

ft_client:
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(UTILS_OBJS) -o $(CLIENT_NAME)

clean:
	$(RM) $(UTILS_OBJS) $(CLIENT_OBJS) $(SERVER_OBJS)

fclean:	clean
	$(RM) $(SERVER_NAME) $(CLIENT_NAME)

re:	fclean all

.PHONY: all clean fclean server client
