/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:27:41 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/08 00:52:40 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_top(size_t idx_a, t_stack *stack_a, size_t idx_b,
			t_stack *stack_b)
{
	if (idx_a <= (stack_a->size >> 1))
		rotate("ra\n", stack_a, idx_a);
	else
		reverse_rotate("rra\n", stack_a, stack_a->size - idx_a);
	if (idx_b <= (stack_b->size >> 1))
		rotate("rb\n", stack_b, idx_b);
	else
		reverse_rotate("rrb\n", stack_b, stack_b->size - idx_b);
}

void	sync_rotate_up(size_t idx_a, t_stack *stack_a, size_t idx_b,
			t_stack *stack_b)
{
	if (idx_a < idx_b)
	{
		rrotate("rr\n", stack_a, stack_b, idx_a);
		idx_b -= idx_a;
		idx_a = 0;
	}
	else
	{
		rrotate("rr\n", stack_a, stack_b, idx_b);
		idx_a -= idx_b;
		idx_b = 0;
	}
	rotate_to_top(idx_a, stack_a, idx_b, stack_b);
}

void	sync_rotate_down(size_t idx_a, t_stack *stack_a, size_t idx_b,
			t_stack *stack_b)
{
	const size_t	size_a = stack_a->size;
	const size_t	size_b = stack_b->size;
	const size_t	dist_a = size_a - idx_a;
	const size_t	dist_b = size_b - idx_b;

	if (!idx_a || !idx_b)
		return (rotate_to_top(idx_a, stack_a, idx_b, stack_b));
	if (dist_a < dist_b)
	{
		rreverse_rotate("rrr\n", stack_a, stack_b, dist_a);
		idx_b = (dist_a + idx_b) % size_b;
		idx_a = 0;
	}
	else
	{
		rreverse_rotate("rrr\n", stack_a, stack_b, dist_b);
		idx_a = (dist_b + idx_a) % size_a;
		idx_b = 0;
	}
	rotate_to_top(idx_a, stack_a, idx_b, stack_b);
}
