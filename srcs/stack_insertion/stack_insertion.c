/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_insertion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:26:07 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/04 09:26:46 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static inline
size_t	puttop_cost(size_t dst_size, size_t dst, size_t src_size, size_t src)
{
	size_t	cost;

	cost = 0;
	if (src <= (src_size >> 1))
		cost += src;
	else
		cost += src_size - src;
	if (dst <= (dst_size >> 1))
		cost += dst;
	else
		cost += dst_size - dst;
	return (cost);
}

static inline
size_t	rev_puttop_together_cost(size_t dst_size, size_t dst, size_t src_size, size_t src)
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
	return (cost + puttop_cost(dst_size, dst, src_size, src));
}

static inline
size_t	puttop_together_cost(size_t dst_size, size_t dst, size_t src_size, size_t src)
{
	size_t	cost;

	if (dst < src)
	{
		cost = dst;
		src -= dst;
		dst = 0;
	}
	else
	{
		cost = src;
		dst -= src;
		src = 0;
	}
	return (cost + puttop_cost(dst_size, dst, src_size, src));
}

size_t	stack_insertion(size_t dst_size, size_t dst, size_t src_size, size_t src)
{
	const int	dst_half = dst <= (dst_size >> 1);
	const int	src_half = src <= (src_size >> 1);
	size_t		min_cost;
	size_t		new_cost;

	if (dst_half && src_half)
		return (puttop_together_cost(dst_size, dst, src_size, src) + 1);
	if (!dst_half && !src_half)
		return (rev_puttop_together_cost(dst_size, dst, src_size, src) + 1);
	min_cost = puttop_together_cost(dst_size, dst, src_size, src);
	new_cost = rev_puttop_together_cost(dst_size, dst, src_size, src);
	if (new_cost < min_cost)
		min_cost = new_cost;
	new_cost = puttop_cost(dst_size, dst, src_size, src);
	if (new_cost < min_cost)
		min_cost = new_cost;
	return (min_cost + 1);
}
