/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithmn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:28:05 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/03 18:30:53 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

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

void	turk_algorithmn(size_t size, int stack_a[size], int stack_b[size])
{
	push_top(stack_b, stack_a);
}
