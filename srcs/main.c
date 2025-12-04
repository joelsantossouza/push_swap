/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:06:39 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/04 09:22:36 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 5)
		return (1);
	const size_t	dst_size = atoi(argv[1]);
	const size_t	dst = atoi(argv[2]);
	const size_t	src_size = atoi(argv[3]);
	const size_t	src = atoi(argv[4]);
	size_t	i = -1;

	while (++i < dst_size || i < src_size)
	{
		printf("%3lu) ", i);
		printf(i < dst_size ? "%5s " : "      ", i == dst ? "X" : "o");
		printf(i < src_size ? "%5s " : "      ", i == src ? "X" : "o");
		printf("\n");
	}
	printf("\n-- Min cost = %lu --\n", stack_insertion_cost(dst_size, dst, src_size, src));
	return (0);
}
