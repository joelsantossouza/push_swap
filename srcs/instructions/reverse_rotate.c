/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:45:04 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/03 23:08:20 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	reverse_rotate_a(size_t size_a, int stack_a[size_a])
{
	int	last_value;

	if (size_a < 2)
		return ;
	last_value = stack_a[size_a - 1];
	ft_memmove(stack_a + 1, stack_a, (size_a - 1) * sizeof(int));
	stack_a[0] = last_value;
	write(STDOUT_FILENO, "ra\n", 3);
}

void	reverse_rotate_b(size_t size_b, int stack_b[size_b])
{
	int	last_value;

	if (size_b < 2)
		return ;
	last_value = stack_b[size_b - 1];
	ft_memmove(stack_b + 1, stack_b, (size_b - 1) * sizeof(int));
	stack_b[0] = last_value;
	write(STDOUT_FILENO, "rb\n", 3);
}
