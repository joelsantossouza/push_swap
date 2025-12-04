/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_insertion_cost.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 22:43:57 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/04 00:38:37 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	stack_insertion_cost(size_t dst_size, size_t dst, size_t src_size, size_t src)
{
	const int	dst_half = !dst || dst < (dst_size >> 1);
	const int	src_half = !src || src < (src_size >> 1);
	size_t		min_cost;
	size_t		new_cost;

	if (dst_half && src_half)
		return (rotate_cost(dst_size, dst, src_size, src));
	if (!dst_half && !src_half)
		return (reverse_rotate_cost(dst_size, dst, src_size, src));
	min_cost = rotate_cost(dst_size, dst, src_size, src);
	new_cost = reverse_rotate_cost(dst_size, dst, src_size, src);
	if (new_cost < min_cost)
		min_cost = new_cost;
	if (!src || src < (src_size >> 1))
		new_cost += src;
	else
		cost += src_size - src;
	if (!dst || dst < (dst_size >> 1))
		cost += dst;
	else
		cost += dst_size - dst;
}
