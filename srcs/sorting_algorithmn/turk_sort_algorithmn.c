/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_algorithmn.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:28:05 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/07 13:02:33 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline
void	cheapest_push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	size_t	idx[2];
	size_t	min_cost;
	size_t	new_cost;
	size_t	new_idx;
	size_t	size_b;

	size_b = stack_b->size;
	idx[1] = --size_b;
	idx[0] = stack_insertion_finder(stack_b->data[size_b], stack_a);
	min_cost = stack_insertion_cost(idx[0], stack_a->size,
			size_b, stack_b->size);
	while (size_b-- && min_cost > 1)
	{
		new_idx = stack_insertion_finder(stack_b->data[size_b], stack_a);
		new_cost = stack_insertion_cost(new_idx, stack_a->size,
				size_b, stack_b->size);
		if (new_cost < min_cost)
		{
			min_cost = new_cost;
			idx[1] = size_b;
			idx[0] = new_idx;
		}
	}
	stack_insertion_align(idx[0], stack_a, idx[1], stack_b);
	push_to("pa\n", stack_a, stack_b);
}

static inline
void	last_three_elements_sort(t_stack *stack_a)
{
	const size_t	size = stack_a->size;
	const int		*data = stack_a->data;

	if (size > 2)
	{
		if (data[0] > data[1] && data[0] > data[2])
			rotate("ra\n", stack_a, 1);
		if (data[0] > data[2])
			reverse_rotate("rra\n", stack_a, 1);
		if (data[1] > data[2])
		{
			reverse_rotate("rra\n", stack_a, 1);
			swap_top("sa\n", stack_a);
		}
	}
	if (size > 1 && data[0] > data[1])
		swap_top("sa\n", stack_a);
}

static inline
size_t	get_min_value_idx(int *data, size_t size)
{
	size_t	min_value_idx;
	int		min_value;

	min_value_idx = size - (size != 0);
	min_value = data[min_value_idx];
	while (size--)
	{
		if (data[size] < min_value)
		{
			min_value_idx = size;
			min_value = data[size];
		}
	}
	return (min_value_idx);
}

void	turk_sort_algorithmn(t_stack *stack_a, t_stack *stack_b)
{
	size_t	min_value_idx;

	if (is_sorted(stack_a->data, stack_a->size))
		return ;
	while (stack_a->size > 3)
		push_to("pb\n", stack_b, stack_a);
	last_three_elements_sort(stack_a);
	while (stack_b->size)
		cheapest_push_to_a(stack_a, stack_b);
	min_value_idx = get_min_value_idx(stack_a->data, stack_a->size);
	rotate_to_top(min_value_idx, stack_a, 0, stack_b);
}
