/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_insertion_finder.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 22:38:30 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/04 17:45:28 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline
int	get_closest_value_idx(int *data, size_t size, int insert, size_t *idx)
{
	size_t	max_value_idx;
	int		max_value;

	max_value_idx = size - (size != 0);
	max_value = data[max_value_idx];
	while (size--)
	{
		if (data[size] < insert)
		{
			*idx = size;
			return (0);
		}
		if (data[size] > max_value)
		{
			max_value_idx = size;
			max_value = data[size];
		}
	}
	*idx = max_value_idx;
	return (-1);
}

size_t	stack_insertion_finder(int insert, t_stack *stack, int flags)
{
	const int	*data = stack->data;
	const int	dir = 1 - 2 * (flags == BELOW);
	const int	closest_max_value = insert + dir;
	size_t		closest;
	size_t		size;

	if (get_closest_value_idx(stack->data, stack->size, insert, &closest) < 0)
		return (closest);
	size = closest;
	while (size-- && data[closest] != closest_max_value)
		if ((data[size] - insert) * dir < 0 && (data[size] - data[closest]) * dir > 0)
			closest = size;
	return (closest);
}
