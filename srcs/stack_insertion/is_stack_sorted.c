/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stack_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 00:03:32 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/08 00:10:59 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack *stack)
{
	const int		*data = stack->data;
	const size_t	size = stack->size;
	size_t			start;
	size_t			i;
	size_t			next;

	if (stack->size < 2)
		return (1);
	start = get_min(stack->data, stack->size);
	i = start;
	while (i != start)
	{
		next = (i + 1) % size;
		if (data[i] > data[next])
			return (0);
		i = next;
	}
	return (1);
}
