# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/02 18:19:34 by joesanto          #+#    #+#              #
#    Updated: 2025/12/08 00:11:57 by joesanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CC = cc
FLAGS = -Wall -Wextra -Werror -g

SRCS_DIR = srcs
SRCS_BONUS_DIR = srcs_bonus

PARSING_DIR = $(SRCS_DIR)/parsing
PARSING = $(addprefix $(PARSING_DIR)/, parse_stack_str.c parse_stack_lst.c \
		  error.c)

SORTING_ALGORITHMN_DIR = $(SRCS_DIR)/sorting_algorithmn
SORTING_ALGORITHMN = $(addprefix $(SORTING_ALGORITHMN_DIR)/, turk_sort_algorithmn.c \
					 is_sorted.c get_min.c)

INSTRUCTIONS_DIR = $(SRCS_DIR)/instructions
INSTRUCTIONS = $(addprefix $(INSTRUCTIONS_DIR)/, rotate.c reverse_rotate.c push_to.c \
			   swap_top.c rotate_to_top.c)

STACK_INSERTION_DIR = $(SRCS_DIR)/stack_insertion
STACK_INSERTION = $(addprefix $(STACK_INSERTION_DIR)/, stack_insertion_finder.c \
				  stack_insertion_align.c is_stack_sorted.c)

COST_DIR = $(SRCS_DIR)/cost
COST = $(addprefix $(COST_DIR)/, rotate_to_top_cost.c stack_insertion_cost.c)

CHECKER_DIR = $(SRCS_BONUS_DIR)/checker
CHECKER = $(CHECKER_DIR)/push_swap_checker_bonus.c

MAIN = $(SRCS_DIR)/main.c
MAIN_BONUS = $(SRCS_BONUS_DIR)/main_bonus.c

HEADERS_DIR = includes
HEADERS = $(HEADERS_DIR)/push_swap.h

OBJS = $(MAIN:.c=.o) $(PARSING:.c=.o) $(SORTING_ALGORITHMN:.c=.o) $(INSTRUCTIONS:.c=.o) \
	$(STACK_INSERTION:.c=.o) $(COST:.c=.o)
OBJS_BONUS = $(MAIN_BONUS:.c=.o) $(PARSING:.c=.o) $(CHECKER:.c=.o) $(INSTRUCTIONS:.c=.o) \
	$(SORTING_ALGORITHMN_DIR)/is_sorted.c
LIBS_DIR = libs
LIBFT = $(LIBS_DIR)/libft/libft.a
INCLUDES = $(addprefix -I, $(LIBS_DIR)/libft $(HEADERS_DIR))

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -o $@

$(NAME_BONUS): $(LIBFT) $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) $(LIBFT) -o $@

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
