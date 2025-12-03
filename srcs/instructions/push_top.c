/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:33:06 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/03 18:44:35 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top(size_t dst_size, int dst[dst_size], size_t src_size, int src[src_size])
{
	if (!src_size)
		return ;
	rotate(dst_size + 1, dst);
	dst[0] = src[0];
}
