/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:45:04 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/03 18:48:41 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rotate(size_t size, int stack[size])
{
	const int last_value = stack[size - 1];

	ft_memmove(stack + 1, stack, (size - 1) * sizeof(int));
	stack[0] = last_value;
}
