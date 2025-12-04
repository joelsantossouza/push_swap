/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:06:39 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/04 13:31:04 by joesanto         ###   ########.fr       */
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
	if (argc != 5)
		return (1);
	srand(time(0));
	const size_t	idx_a = atoi(argv[1]);
	const size_t	size_a = atoi(argv[2]);
	const size_t	idx_b = atoi(argv[3]);
	const size_t	size_b = atoi(argv[4]);
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
		printf(i < size_a ? "%5d%s " : "      ", a.data[i], i == idx_a ? "." : "");
		printf(i < size_b ? "%5d%s " : "      ", b.data[i], i == idx_b ? "." : "");
		printf("\n");
	}
	printf("\n-- Min cost = %lu --\n", stack_insertion_cost(idx_a, size_a, idx_b, size_b));

	stack_insertion_align(idx_a, &a, idx_b, &b);
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
