/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:33:06 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/03 19:20:30 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	push_to_a(size_t *size_a, int stack_a[*size_a], size_t *size_b, int stack_b[*size_b])
{
	if (!size_b)
		return ;
	ft_memmove(stack_a + 1, stack_a, (*size_a)++);
	stack_a[0] = stack_b[0];
	ft_memmove(stack_b, stack_b + 1, --(*size_b));
	write(STDOUT_FILENO, "pa\n", 3);
}

void	push_to_b(size_t *size_b, int stack_b[*size_b], size_t *size_a, int stack_a[*size_a])
{
	if (!size_a)
		return ;
	ft_memmove(stack_b + 1, stack_b, (*size_b)++);
	stack_b[0] = stack_a[0];
	ft_memmove(stack_a, stack_a + 1, --(*size_a));
	write(STDOUT_FILENO, "pb\n", 3);
}
