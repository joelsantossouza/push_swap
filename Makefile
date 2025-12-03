# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/02 18:19:34 by joesanto          #+#    #+#              #
#    Updated: 2025/12/03 17:56:37 by joesanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror -g

SRCS_DIR = srcs

PARSING_DIR = $(SRCS_DIR)/parsing
PARSING = $(PARSING_DIR)/parse_stack.c

SORTING_DIR = $(SRCS_DIR)/sorting
SORTING = $(SORTING_DIR)/turk_algorithmn.c

MAIN = $(SRCS_DIR)/main.c

HEADERS_DIR = includes
HEADERS = $(HEADERS_DIR)/push_swap.h

OBJS = $(MAIN:.c=.o) $(PARSING:.c=.o) $(SORTING:.c=.o)
LIBS_DIR = libs
LIBFT = $(LIBS_DIR)/libft/libft.a
INCLUDES = $(addprefix -I, $(LIBS_DIR)/libft $(HEADERS_DIR))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -o $@

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@if [ ! -d "$(dir $@)" ]; then \
		git clone git@github.com:joelsantossouza/libft.git $(dir $@); \
	fi
	make -C $(dir $@)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(LIBS_DIR)

re: fclean all
