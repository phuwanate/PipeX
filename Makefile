# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 10:44:04 by plertsir          #+#    #+#              #
#    Updated: 2023/06/21 12:49:27 by plertsir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc -g
FLAGS = -Wall -Werror -Wextra
LIBARIES = -lft -L$(LIBFT_DIRECTORY)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_DIRECTORY)

LIBFT_DIRECTORY = ./libft/
LIBFT = $(LIBFT_DIRECTORY)libft.a

HEADERS_LIST = pipex.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY_A = ./sources/main/
SOURCES_LIST_A = pipex.c

SOURCES_DIRECTORY_D = ./sources/utils/
SOURCES_LIST_D = utils.c

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST_A = $(patsubst %.c, %.o, $(SOURCES_LIST_A))
OBJECTS_LIST_D = $(patsubst %.c, %.o, $(SOURCES_LIST_D))
OBJECTS_A = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_A))
OBJECTS_D = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_D))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS_A) $(OBJECTS_D)
	$(CC) $(FLAGS) $(LIBARIES) $(INCLUDES) $(OBJECTS_A) $(OBJECTS_D) -o $(NAME)

$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY_A)%.c $(HEADERS)
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY_D)%.c $(HEADERS)
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	rm -rf $(LIBFT)
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
