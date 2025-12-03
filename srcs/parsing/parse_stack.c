/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:23:12 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/03 12:58:03 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int	parse_stack(size_t size, int stack[size], char **numbers)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (*numbers && ++i < size)
	{
		if (!ft_is_str_numeric(*numbers))
			return (-1);
		if (ft_nbrcmp(*numbers, "") < 0)
			return (-1);
		if (ft_nbrcmp(*numbers, "") > 0)
			return (-1);
		stack[i] = ft_atol_base(*numbers++, 0, "0123456789");
		j = -1;
		while (++j < i)
			if (stack[j] == stack[i])
				return (-1);
	}
	return (0);
}
