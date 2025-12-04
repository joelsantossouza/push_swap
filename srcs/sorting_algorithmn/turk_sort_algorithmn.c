/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_algorithmn.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:28:05 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/04 15:26:28 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline
void	cheapest_insertion_align(t_stack *dst, t_stack *src, size_t *dst_idx, size_t *src_idx)
{
	size_t	min_cost;
	size_t	new_cost;
	size_t	new_dst_idx;
	size_t	src_size;

	src_size = src->size;
	*src_idx = --src_size;
	*dst_idx = stack_insertion_finder(src->data[src_size], dst);
	min_cost = stack_insertion_cost(src_size, src->size, *dst_idx, dst->size);
	while (src_size-- && min_cost > 1)
	{
		new_dst_idx = stack_insertion_finder(src->data[src_size], dst);
		new_cost = stack_insertion_cost(src_size, src->size, new_dst_idx, dst->size);
		if (new_cost < min_cost)
		{
			min_cost = new_cost;
			*src_idx = src_size;
			*dst_idx = new_dst_idx;
		}
	}
}

static inline
void	last_three_elements_sort(t_stack *stack_a)
{
	const size_t	size = stack_a->size;
	const int		*data = stack_a->data;

	if (size < 2)
		return ;
	if (data[0] > data[1])
		swap_top("sa\n", stack_a);
	if (size > 2)
	{
		if (data[0] > data[2])
			reverse_rotate("rra\n", stack_a, 1);
		if (data[1] > data[2])
		{
			reverse_rotate("rra\n", stack_a, 1);
			swap_top("sa\n", stack_a);
		}
	}
}

void	turk_sort_algorithmn(t_stack *stack_a, t_stack *stack_b)
{
	size_t	idx_a;
	size_t	idx_b;

	if (stack_a->size > 3)
		push_to("pb\n", stack_b, stack_a);
	if (stack_a->size > 3)
		push_to("pb\n", stack_b, stack_a);
	while (stack_a->size > 3)
	{
		cheapest_insertion_align(stack_b, stack_a, &idx_b, &idx_a);
		stack_insertion_align(idx_a, stack_a, idx_b, stack_b);
		push_to("pb\n", stack_b, stack_a);
	}
	last_three_elements_sort(stack_a);
}
