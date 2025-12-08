/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_top_cost.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:29:41 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/08 00:50:08 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	rotate_to_top_cost(size_t idx_a, size_t size_a, size_t idx_b,
			size_t size_b)
{
	size_t	cost;

	if (idx_a <= (size_a >> 1))
		cost = idx_a;
	else
		cost = size_a - idx_a;
	if (idx_b <= (size_b >> 1))
		cost += idx_b;
	else
		cost += size_b - idx_b;
	return (cost);
}

size_t	sync_rotate_up_cost(size_t idx_a, size_t size_a, size_t idx_b,
			size_t size_b)
{
	size_t	cost;

	if (idx_a < idx_b)
	{
		cost = idx_a;
		idx_b -= idx_a;
		idx_a = 0;
	}
	else
	{
		cost = idx_b;
		idx_a -= idx_b;
		idx_b = 0;
	}
	return (cost + rotate_to_top_cost(idx_a, size_a, idx_b, size_b));
}

size_t	sync_rotate_down_cost(size_t idx_a, size_t size_a, size_t idx_b,
			size_t size_b)
{
	const size_t	dist_a = size_a - idx_a;
	const size_t	dist_b = size_b - idx_b;
	size_t			cost;

	if (!idx_a || !idx_b)
		cost = 0;
	else if (dist_a < dist_b)
	{
		cost = dist_a;
		idx_b = (dist_a + idx_b) % size_b;
		idx_a = 0;
	}
	else
	{
		cost = dist_b;
		idx_a = (dist_b + idx_a) % size_a;
		idx_b = 0;
	}
	return (cost + rotate_to_top_cost(idx_a, size_a, idx_b, size_b));
}
