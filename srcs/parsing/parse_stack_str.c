/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:54:10 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/05 16:31:51 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

int	parse_stack_str(t_stack *stack, char *numbers)
{
	const size_t	size = ft_word_count(numbers, ' ');
	char			**splited;
	int				stats;

	splited = ft_split(numbers, ' ');
	if (!splited)
		return (-1);
	stats = parse_stack_lst(stack, size, splited);
	ft_freearray((void **) splited, free);
	return (stats);
}
