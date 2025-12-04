/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:06:39 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/04 15:25:22 by joesanto         ###   ########.fr       */
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
	if (argc != 3)
		return (1);
	srand(time(0));
	const size_t	size_a = atoi(argv[1]);
	const size_t	size_b = atoi(argv[2]);
	t_stack	a = {
		malloc(sizeof(int) * size_a),
		size_a,
	};
	t_stack	b = {
		malloc(sizeof(int) * size_b),
		size_b,
	};
	init_random(&a);
	init_random(&b);

	size_t	i = -1;
	while (++i < size_a || i < size_b)
	{
		printf("%3lu) ", i);
		printf(i < size_a ? "%5d " : "      ", a.data[i]);
		printf(i < size_b ? "%5d " : "      ", b.data[i]);
		printf("\n");
	}

	turk_sort_algorithmn(&a, &b);
	i = -1;
	printf("\n");
	while (++i < size_a || i < size_b)
	{
		printf("%3lu) ", i);
		printf(i < size_a ? "%5d " : "      ", a.data[i]);
		printf(i < size_b ? "%5d " : "      ", b.data[i]);
		printf("\n");
	}
	return (0);
}
