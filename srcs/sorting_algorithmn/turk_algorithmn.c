/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithmn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:28:05 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/04 13:11:15 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_algorithmn(size_t size_a, int stack_a[size_a], size_t size_b, int stack_b[size_b])
{
	size_t	i;
	size_t	new_cost;
	size_t	max_cost;
	size_t	insertion_idx;

	(void)new_cost;
	(void)max_cost;
	(void)stack_b;
//	push_to("pb\n", stack_b, stack_a);
//	push_to("pb\n", stack_b, stack_a);
	while (size_a > 3)
	{
		i = -1;
		while (++i < size_a)
		{
			//insertion_idx = stack_insertion_finder(stack_a[i], size_b, stack_b);
			insertion_idx = 0;
			new_cost = stack_insertion_cost(insertion_idx, stack_a[i], size_b, size_a);
		}
	}
}
