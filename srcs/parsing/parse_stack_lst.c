/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:23:12 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/05 16:05:19 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static inline
int	ft_is_str_numeric(const char *str)
{
	str += *str == '-' || *str == '+';
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	parse_stack_lst(t_stack *stack, char **numbers)
{
	const size_t	size = stack->size;
	size_t			i;
	size_t			j;

	i = -1;
	while (*numbers && ++i < size)
	{
		if (!ft_is_str_numeric(*numbers))
			return (error(), -1);
		if (ft_nbrcmp(*numbers, "-2147483648") < 0)
			return (error(), -1);
		if (ft_nbrcmp(*numbers, "2147483647") > 0)
			return (error(), -1);
		stack->data[i] = ft_atol_base(*numbers++, 0, "0123456789");
		j = -1;
		while (++j < i)
			if (stack->data[j] == stack->data[i])
				return (error(), -1);
	}
	return (0);
}
