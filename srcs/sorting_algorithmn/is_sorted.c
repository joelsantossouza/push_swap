/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:22:55 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/05 10:23:55 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	is_sorted(int *data, size_t size)
{
	if (size < 2)
		return (1);
	while (size-- > 1)
		if (data[size] < data[size - 1])
			return (0);
	return (1);
}
