/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:03:26 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/08 01:06:22 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <sys/types.h>

typedef struct s_stack
{
	int		*data;
	size_t	size;
}	t_stack;

typedef void	(*t_align_to_top)(size_t, t_stack *, size_t, t_stack *);
typedef ssize_t	(*t_stack_find)(int, t_stack *);

// PARSING
int		error(void);
int		parse_stack_lst(t_stack *stack, size_t size, char **numbers);
int		parse_stack_str(t_stack *stack, char *numbers);

// INSTRUCTIONS
int		swap_top(const char *motion, t_stack *stack);
int		sswap_top(const char *motion, t_stack *stack_a, t_stack *stack_b);
int		push_to(const char *motion, t_stack *dst, t_stack *src);
int		rotate(const char *motion, t_stack *stack, size_t times);
int		rrotate(const char *motion, t_stack *stack_a, t_stack *stack_b,
			size_t times);
int		reverse_rotate(const char *motion, t_stack *stack, size_t times);
int		rreverse_rotate(const char *motion, t_stack *stack_a, t_stack *stack_b,
			size_t times);

void	rotate_to_top(size_t idx_a, t_stack *stack_a, size_t idx_b,
			t_stack *stack_b);
void	sync_rotate_up(size_t idx_a, t_stack *stack_a, size_t idx_b,
			t_stack *stack_b);
void	sync_rotate_down(size_t idx_a, t_stack *stack_a, size_t idx_b,
			t_stack *stack_b);

// COST
size_t	rotate_to_top_cost(size_t idx_a, size_t size_a, size_t idx_b,
			size_t size_b);
size_t	sync_rotate_up_cost(size_t idx_a, size_t size_a, size_t idx_b,
			size_t size_b);
size_t	sync_rotate_down_cost(size_t idx_a, size_t size_a, size_t idx_b,
			size_t size_b);
size_t	stack_insertion_cost(size_t idx_a, size_t size_a, size_t idx_b,
			size_t size_b);

// STACK INSERTION
ssize_t	smallest_greater(int insert, t_stack *stack);
ssize_t	greatest_smaller(int insert, t_stack *stack);
void	stack_insertion_align(size_t idx_a, t_stack *stack_a, size_t idx_b,
			t_stack *stack_b);

// SORTING ALGORITHMN
int		is_sorted(int *data, size_t size);
void	turk_sort_algorithmn(t_stack *stack_a, t_stack *stack_b);

#endif
