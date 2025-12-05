/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:45:04 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/05 11:58:13 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

int	reverse_rotate(const char *motion, t_stack *stack, size_t times)
{
	int	last_value;
	int	last_idx;

	if (stack->size < 2)
		return (-1);
	last_idx = stack->size - 1;
	while (times--)
	{
		last_value = stack->data[last_idx];
		ft_memmove(stack->data + 1, stack->data, sizeof(int) * last_idx);
		stack->data[0] = last_value;
		ft_putstr_fd(motion, STDOUT_FILENO);
	}
	return (0);
}

int	rreverse_rotate(const char *motion, t_stack *stack_a, t_stack *stack_b,
		size_t times)
{
	const int	stats = reverse_rotate("", stack_a, times)
		* reverse_rotate("", stack_b, times);

	if (stats < 0)
		return (-1);
	if (*motion)
		while (times--)
			ft_putstr_fd(motion, STDOUT_FILENO);
	return (0);
}
