/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_insertion_finder.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 22:38:30 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/07 13:09:28 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t	stack_insertion_finder(int insert, t_stack *stack)
{
	const int	*data = stack->data;
	size_t		size;
	size_t		min;
	size_t		closest;

	size = stack->size;
	if (!size)
		return (-1);
	min = --size;
	while (1)
	{
		if (data[size] > insert)
			break ;
		if (data[size] < data[min])
			min = size;
		if (!size--)
			return (min);
	}
	closest = size;
	while (size--)
		if (data[size] > insert && data[size] < data[closest])
			closest = size;
	return (closest);
}
