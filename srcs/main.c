/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:06:39 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/04 21:32:50 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void	init_random(t_stack *stack)
{
	size_t	size;

	size = stack->size;
	while (size--)
		stack->data[size] = rand() % 255;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	srand(time(0));
	t_stack	a = {
		malloc(sizeof(int) * argc - 1),
		argc - 1,
	};
	t_stack	b = {
		malloc(sizeof(int) * argc - 1),
		0,
	};
	parse_stack(&a, argv + 1);

	turk_sort_algorithmn(&a, &b);

	//size_t	i = -1;
	//while (++i < a.size || i < b.size)
	//{
	//	printf("%3lu) ", i);
	//	printf(i < a.size ? "%5d " : "      ", a.data[i]);
	//	printf(i < b.size ? "%5d " : "      ", b.data[i]);
	//	printf("\n");
	//}

	//turk_sort_algorithmn(&a, &b);
	//i = -1;
	//printf("\n");
	//while (++i < a.size || i < b.size)
	//{
	//	printf("%3lu) ", i);
	//	printf(i < a.size ? "%5d " : "      ", a.data[i]);
	//	printf(i < b.size ? "%5d " : "      ", b.data[i]);
	//	printf("\n");
	//}
	//return (0);
}
