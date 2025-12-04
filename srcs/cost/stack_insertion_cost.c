/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_insertion_cost.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:16:25 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/04 11:24:56 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stack_insertion_cost(size_t idx_a, size_t size_a, size_t idx_b, size_t size_b)
{
	const int	a_half = idx_a <= (size_a >> 1);
	const int	b_half = idx_b <= (size_b >> 1);
	size_t		min_cost;
	size_t		new_cost;

	if (a_half && b_half)
		return (1 + sync_rotate_up_cost(idx_a, size_a, idx_b, size_b));
	if (!a_half && !b_half)
		return (1 + sync_rotate_down_cost(idx_a, size_a, idx_b, size_b));
	min_cost = sync_rotate_up_cost(idx_a, size_a, idx_b, size_b);
	new_cost = sync_rotate_down_cost(idx_a, size_a, idx_b, size_b);
	if (new_cost < min_cost)
		min_cost = new_cost;
	new_cost = rotate_to_top_cost(idx_a, size_a, idx_b, size_b);
	if (new_cost < min_cost)
		min_cost = new_cost;
	return (1 + min_cost);
}
