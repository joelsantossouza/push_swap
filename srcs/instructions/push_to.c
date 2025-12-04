/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:33:06 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/04 12:33:39 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

int	push_to(const char *motion, t_stack *dst, t_stack *src)
{
	if (!src->size)
		return (-1);
	ft_memmove(dst->data + 1, dst->data, sizeof(int) * dst->size++);
	dst->data[0] = src->data[0];
	ft_memmove(src->data, src->data + 1, sizeof(int) * --src->size);
	ft_putstr_fd(motion, STDOUT_FILENO);
	return (0);
}
