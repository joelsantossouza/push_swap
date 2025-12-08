/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 00:04:46 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/08 00:05:32 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

ssize_t	get_min(int *data, size_t size)
{
	size_t	min_value_idx;
	int		min_value;

	if (!size)
		return (-1);
	min_value_idx = --size;
	min_value = data[min_value_idx];
	while (size--)
	{
		if (data[size] < min_value)
		{
			min_value_idx = size;
			min_value = data[size];
		}
	}
	return (min_value_idx);
}
