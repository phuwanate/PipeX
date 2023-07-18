# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 10:44:04 by plertsir          #+#    #+#              #
#    Updated: 2023/07/18 14:34:30 by plertsir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
FLAGS = -Wall -Werror -Wextra -g
LIBARIES = -lft -L$(LIBFT_DIRECTORY)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_DIRECTORY)
INCLUDES_BONUS = -I$(HEADERS_DIRECTORY_BONUS) -I$(LIBFT_DIRECTORY)

LIBFT_DIRECTORY = ./libft/
LIBFT = $(LIBFT_DIRECTORY)libft.a

HEADERS_LIST = pipex.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

HEADERS_LIST_BONUS = pipex_bonus.h get_next_line_bonus.h
HEADERS_DIRECTORY_BONUS = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY_BONUS), $(HEADERS_LIST_BONUS))

# Regular sources
SOURCES_DIRECTORY_A = ./sources/mandatory/main/
SOURCES_LIST_A = pipex.c execute.c close_pipe.c

SOURCES_DIRECTORY_B = ./sources/mandatory/input/
SOURCES_LIST_B = get_cmd.c get_path.c

SOURCES_DIRECTORY_C = ./sources/mandatory/handle_error/
SOURCES_LIST_C = input_error.c

SOURCES_DIRECTORY_D = ./sources/mandatory/utils/
SOURCES_LIST_D = utils.c free_mem.c

# Bonus sources
SOURCES_DIRECTORY_A_BONUS = ./sources/bonus/main/
SOURCES_LIST_A_BONUS = pipex_bonus.c execute_bonus.c close_pipe_bonus.c \
					heredoc_bonus.c fork_heredoc_bonus.c fork_infile_bonus.c

SOURCES_DIRECTORY_B_BONUS = ./sources/bonus/input/
SOURCES_LIST_B_BONUS = get_cmd_bonus.c get_path_bonus.c

SOURCES_DIRECTORY_C_BONUS = ./sources/bonus/handle_error/
SOURCES_LIST_C_BONUS = input_error_bonus.c

SOURCES_DIRECTORY_D_BONUS = ./sources/bonus/utils/
SOURCES_LIST_D_BONUS = utils_bonus.c free_mem_bonus.c get_next_line_utils_bonus.c \
					get_next_line_bonus.c

OBJECTS_DIRECTORY = objects/
OBJECTS_DIRECTORY_BONUS = objects_bonus/
OBJECTS_LIST_A = $(patsubst %.c, %.o, $(SOURCES_LIST_A))
OBJECTS_LIST_B = $(patsubst %.c, %.o, $(SOURCES_LIST_B))
OBJECTS_LIST_C = $(patsubst %.c, %.o, $(SOURCES_LIST_C))
OBJECTS_LIST_D = $(patsubst %.c, %.o, $(SOURCES_LIST_D))
OBJECTS_LIST_A_BONUS = $(patsubst %.c, %.o, $(SOURCES_LIST_A_BONUS))
OBJECTS_LIST_B_BONUS = $(patsubst %.c, %.o, $(SOURCES_LIST_B_BONUS))
OBJECTS_LIST_C_BONUS = $(patsubst %.c, %.o, $(SOURCES_LIST_C_BONUS))
OBJECTS_LIST_D_BONUS = $(patsubst %.c, %.o, $(SOURCES_LIST_D_BONUS))
OBJECTS_A = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_A))
OBJECTS_B = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_B))
OBJECTS_C = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_C))
OBJECTS_D = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_D))
OBJECTS_A_BONUS = $(addprefix $(OBJECTS_DIRECTORY_BONUS), $(OBJECTS_LIST_A_BONUS))
OBJECTS_B_BONUS = $(addprefix $(OBJECTS_DIRECTORY_BONUS), $(OBJECTS_LIST_B_BONUS))
OBJECTS_C_BONUS = $(addprefix $(OBJECTS_DIRECTORY_BONUS), $(OBJECTS_LIST_C_BONUS))
OBJECTS_D_BONUS = $(addprefix $(OBJECTS_DIRECTORY_BONUS), $(OBJECTS_LIST_D_BONUS))

.PHONY: all clean fclean re bonus

# Regular target
all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS_A) $(OBJECTS_B) $(OBJECTS_C) $(OBJECTS_D)
	$(CC) $(FLAGS) $(LIBARIES) $(INCLUDES) $(OBJECTS_A) $(OBJECTS_B) $(OBJECTS_C) $(OBJECTS_D) -o $(NAME)

$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY_A)%.c $(HEADERS)
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY_B)%.c $(HEADERS)
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY_C)%.c $(HEADERS)
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY_D)%.c $(HEADERS)
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

# Bonus target
bonus: FLAGS += -DBONUS
bonus: $(LIBFT) $(OBJECTS_DIRECTORY_BONUS) $(OBJECTS_A_BONUS) $(OBJECTS_B_BONUS) $(OBJECTS_C_BONUS) $(OBJECTS_D_BONUS)
	$(CC) $(FLAGS) $(LIBARIES) $(INCLUDES) $(OBJECTS_A_BONUS) $(OBJECTS_B_BONUS) $(OBJECTS_C_BONUS) $(OBJECTS_D_BONUS) -o $(NAME)

$(OBJECTS_DIRECTORY_BONUS):
	mkdir -p $(OBJECTS_DIRECTORY_BONUS)


$(OBJECTS_DIRECTORY_BONUS)%.o: $(SOURCES_DIRECTORY_A_BONUS)%.c $(HEADERS)
	$(CC) $(FLAGS) -c $(INCLUDES_BONUS) $< -o $@

$(OBJECTS_DIRECTORY_BONUS)%.o: $(SOURCES_DIRECTORY_B_BONUS)%.c $(HEADERS)
	$(CC) $(FLAGS) -c $(INCLUDES_BONUS) $< -o $@

$(OBJECTS_DIRECTORY_BONUS)%.o: $(SOURCES_DIRECTORY_C_BONUS)%.c $(HEADERS)
	$(CC) $(FLAGS) -c $(INCLUDES_BONUS) $< -o $@

$(OBJECTS_DIRECTORY_BONUS)%.o: $(SOURCES_DIRECTORY_D_BONUS)%.c $(HEADERS)
	$(CC) $(FLAGS) -c $(INCLUDES_BONUS) $< -o $@

$(LIBFT):
	$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	rm -rf $(OBJECTS_DIRECTORY)
	rm -rf $(OBJECTS_DIRECTORY_BONUS)

fclean: clean
	rm -rf $(LIBFT)
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

rebonus:
	$(MAKE) fclean
	$(MAKE) bonus
