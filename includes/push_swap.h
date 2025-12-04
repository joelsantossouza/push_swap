/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:03:26 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/04 11:36:36 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

typedef struct s_stack
{
	int		*data;
	size_t	size;
}	t_stack;

// PARSING
int		parse_stack(t_stack *stack, char **numbers);

// INSTRUCTIONS
void	reverse_rotate_a(t_stack *stack_a, size_t times);
void	reverse_rotate_b(t_stack *stack_b, size_t times);
void	push_to_a(t_stack *stack_a, t_stack *stack_b);
void	push_to_b(t_stack *stack_a, t_stack *stack_b);

// COST
size_t	rotate_to_top_cost(size_t idx_a, size_t size_a, size_t idx_b, size_t size_b);
size_t	sync_rotate_up_cost(size_t idx_a, size_t size_a, size_t idx_b, size_t size_b);
size_t	sync_rotate_down_cost(size_t idx_a, size_t size_a, size_t idx_b, size_t size_b);
size_t	stack_insertion_cost(size_t idx_a, size_t size_a, size_t idx_b, size_t size_b);

// STACK INSERTION
size_t	stack_insertion_finder(int insert, t_stack *stack);

// SORTING ALGORITHMN

#endif
