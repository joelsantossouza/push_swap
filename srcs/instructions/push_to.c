/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:33:06 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/04 09:41:58 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

void	push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_b->size)
		return ;
	ft_memmove(stack_a->data + 1, stack_a->data, sizeof(int) * stack_a->size++);
	stack_a->data[0] = stack_b->data[0];
	ft_memmove(stack_b->data, stack_b->data + 1, sizeof(int) * --stack_b->size);
	write(STDOUT_FILENO, "pa\n", 3);
}

void	push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a->size)
		return ;
	ft_memmove(stack_b->data + 1, stack_b->data, sizeof(int) * stack_b->size++);
	stack_b->data[0] = stack_a->data[0];
	ft_memmove(stack_a->data, stack_a->data + 1, sizeof(int) * --stack_a->size);
	write(STDOUT_FILENO, "pb\n", 3);
}
