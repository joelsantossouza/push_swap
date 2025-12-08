/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:54:10 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/08 01:42:47 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

int	parse_stack_str(t_stack *stack, char *numbers)
{
	ssize_t	size;
	char	**splited;
	int		stats;

	if (!*numbers)
		return (error(), -1);
	splited = 0;
	size = ft_split(&splited, numbers, ' ');
	if (size < 0)
		return (-1);
	stats = parse_stack_lst(stack, size, splited);
	ft_freearray((void **) splited, free);
	return (stats);
}
