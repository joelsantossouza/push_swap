/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_insertion_finder.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 22:38:30 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/03 22:38:51 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	stack_insertion_finder(int insert, size_t size, int stack[size])
{
	const int	closest_max_value = insert - 1;
	size_t		closest;

	while (size && stack[--size] > insert)
		;
	closest = size;
	while (size-- && stack[closest] < closest_max_value)
		if (stack[size] < insert && stack[size] > stack[closest])
			closest = size;
	return (closest);
}
