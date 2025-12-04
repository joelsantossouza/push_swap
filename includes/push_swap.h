/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:03:26 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/04 09:51:50 by joesanto         ###   ########.fr       */
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
void	reverse_rotate_a(t_stack *stack_a);
void	reverse_rotate_b(t_stack *stack_b);
void	push_to_a(t_stack *stack_a, t_stack *stack_b);
void	push_to_b(t_stack *stack_a, t_stack *stack_b);

// STACK INSERTION
size_t	stack_insertion_finder(int insert, t_stack *stack);
size_t	stack_insertion_cost(size_t dst_size, size_t dst, size_t src_size, size_t src);

// SORTING ALGORITHMN
void	turk_algorithmn(size_t size_a, int stack_a[size_a], size_t size_b, int stack_b[size_b]);

#endif
