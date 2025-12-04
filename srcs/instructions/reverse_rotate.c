/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:45:04 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/04 09:47:08 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

void	reverse_rotate_a(t_stack *stack_a)
{
	int	last_value;
	int	last_idx;

	if (stack_a->size < 2)
		return ;
	last_idx = stack_a->size - 1;
	last_value = stack_a->data[last_idx];
	ft_memmove(stack_a->data + 1, stack_a->data, sizeof(int) * last_idx);
	stack_a->data[0] = last_value;
	write(STDOUT_FILENO, "ra\n", 3);
}

void	reverse_rotate_b(t_stack *stack_b)
{
	int	last_value;
	int	last_idx;

	if (stack_b->size < 2)
		return ;
	last_idx = stack_b->size - 1;
	last_value = stack_b->data[last_idx];
	ft_memmove(stack_b->data + 1, stack_b->data, sizeof(int) * last_idx);
	stack_b->data[0] = last_value;
	write(STDOUT_FILENO, "rb\n", 3);
}
