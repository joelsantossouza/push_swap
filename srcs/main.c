/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:06:39 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/03 17:55:25 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	int	*stack_a = malloc(sizeof(int) * (argc - 1));
	if (!stack_a)
		return (2);
	#include <stdio.h>
	if (parse_stack(argc - 1, stack_a, argv + 1) < 0)
		return (free(stack_a), fprintf(stderr, "Error\n"), 3);
	turk_algorithmn(argc - 1, stack_a, stack_a);
	free(stack_a);
	return (0);
}
