/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_insertion_finder.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 22:38:30 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/04 09:51:30 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stack_insertion_finder(int insert, t_stack *stack)
{
	const int	*data = stack->data;
	const int	closest_max_value = insert - 1;
	size_t		closest;
	size_t		size;

	size = stack->size;
	while (size && data[--size] > insert)
		;
	closest = size;
	while (size-- && data[closest] < closest_max_value)
		if (data[size] < insert && data[size] > data[closest])
			closest = size;
	return (closest);
}
