/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_insertion_align.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:26:07 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/04 22:33:33 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_insertion_align(size_t idx_a, t_stack *stack_a, size_t idx_b,
			t_stack *stack_b)
{
	const int		a_half = idx_a <= (stack_a->size >> 1);
	const int		b_half = idx_b <= (stack_b->size >> 1);
	size_t			mincost;
	size_t			newcost;
	t_align_to_top	align;

	if (a_half && b_half)
		return (sync_rotate_up(idx_a, stack_a, idx_b, stack_b));
	if (!a_half && !b_half)
		return (sync_rotate_down(idx_a, stack_a, idx_b, stack_b));
	align = sync_rotate_up;
	mincost = sync_rotate_up_cost(idx_a, stack_a->size, idx_b, stack_b->size);
	newcost = sync_rotate_down_cost(idx_a, stack_a->size, idx_b, stack_b->size);
	if (newcost < mincost)
	{
		align = sync_rotate_down;
		mincost = newcost;
	}
	newcost = rotate_to_top_cost(idx_a, stack_a->size, idx_b, stack_b->size);
	if (newcost < mincost)
	{
		align = rotate_to_top;
		mincost = newcost;
	}
	align(idx_a, stack_a, idx_b, stack_b);
}
