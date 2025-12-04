/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_cost.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 22:59:14 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/04 00:41:16 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	both_reverse_rotate_cost(size_t dst_size, size_t dst, size_t src_size, size_t src)
{
	size_t	cost;

	if (dst > src)
	{
		cost = (dst_size - dst) % dst_size;
		src += (dst_size - dst) % dst_size;
		dst = 0;
	}
	else
	{
		cost = (src_size - src) % src_size;
		dst += (src_size - src) % src_size;
		src = 0;
	}
	if (!src || src < (src_size >> 1))
		cost += src;
	else
		cost += src_size - src;
	if (!dst || dst < (dst_size >> 1))
		cost += dst;
	else
		cost += dst_size - dst;
	return (cost);
}
