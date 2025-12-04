/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:19:10 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/04 15:22:16 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

int	swap_top(const char *motion, t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return (-1);
	tmp = stack->data[0];
	stack->data[0] = stack->data[1];
	stack->data[1] = tmp;
	ft_putstr_fd(motion, STDOUT_FILENO);
	return (0);
}
