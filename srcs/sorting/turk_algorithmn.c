/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithmn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:28:05 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/03 19:34:17 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline
size_t	stack_insertion_finder(int insert, size_t size, int stack[size])
{
	const int	closest_max_value = insert - 1;
	size_t		closest;

	while (size && stack[--size] > insert)
		;
	closest = size;
	while (size-- && stack[closest] < closest_max_value)
		if (stack[size] < insert && stack[size] > stack[closest])
			closest = size;
	return (closest);
}

static inline
size_t	stack_insertion_cost(size_t	dst, size_t	src, size_t dst_size, size_t src_size)
{
	size_t	insertion_cost;

	insertion_cost = 1;
	if (src < (src_size >> 1))
		insertion_cost += src;
	else
		insertion_cost += src_size - src;
	if (dst < (dst_size >> 1))
		insertion_cost += dst;
	else
		insertion_cost += dst_size - dst;
	return (insertion_cost);
}

void	turk_algorithmn(size_t size_a, int stack_a[size_a], size_t size_b, int stack_b[size_b])
{
	push_to_b(&size_b, stack_b, &size_a, stack_a);
	push_to_b(&size_b, stack_b, &size_a, stack_a);
	#include <stdio.h>
	size_t	i = -1;
	while (++i < size_a || i < size_b)
	{
		printf("[%lu] ", i);
		if (i < size_a)
			printf("%3d ", stack_a[i]);
		else
			printf(" -  ");
		if (i < size_b)
			printf("%3d ", stack_b[i]);
		else
			printf(" -  ");
		printf("\n");
	}
}
