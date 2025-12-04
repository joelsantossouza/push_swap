/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_algorithmn.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:28:05 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/04 22:38:15 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline
void	cheapest_push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	size_t	idx[2];
	size_t	min_cost;
	size_t	new_cost;
	size_t	new_idx;
	size_t	size_a;

	size_a = stack_a->size;
	idx[0] = --size_a;
	idx[1] = stack_insertion_finder(stack_a->data[size_a], stack_b, LESS);
	min_cost = stack_insertion_cost(size_a, stack_a->size,
			idx[1], stack_b->size);
	while (size_a-- && min_cost > 1)
	{
		new_idx = stack_insertion_finder(stack_a->data[size_a], stack_b, LESS);
		new_cost = stack_insertion_cost(size_a, stack_a->size,
				new_idx, stack_b->size);
		if (new_cost < min_cost)
		{
			min_cost = new_cost;
			idx[0] = size_a;
			idx[1] = new_idx;
		}
	}
	stack_insertion_align(idx[0], stack_a, idx[1], stack_b);
	push_to("pb\n", stack_b, stack_a);
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

static inline
int	is_sorted(int *data, size_t size)
{
	if (size < 2)
		return (1);
	while (size-- > 1)
		if (data[size] < data[size - 1])
			return (0);
	return (1);
}

void	turk_sort_algorithmn(t_stack *stack_a, t_stack *stack_b)
{
	size_t	idx;
	size_t	min_value_idx;

	if (is_sorted(stack_a->data, stack_a->size))
		return ;
	if (stack_a->size > 3)
		push_to("pb\n", stack_b, stack_a);
	if (stack_a->size > 3)
		push_to("pb\n", stack_b, stack_a);
	while (stack_a->size > 3)
		cheapest_push_to_b(stack_a, stack_b);
	last_three_elements_sort(stack_a);
	while (stack_b->size)
	{
		idx = stack_insertion_finder(stack_b->data[0], stack_a, GREATER);
		stack_insertion_align((idx + 1) % stack_a->size, stack_a, 0, stack_b);
		push_to("pa\n", stack_a, stack_b);
	}
	min_value_idx = get_min_value_idx(stack_a->data, stack_a->size);
	rotate_to_top(min_value_idx, stack_a, 0, stack_b);
}
