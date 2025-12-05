/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:06:39 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/05 11:03:01 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker_bonus.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		stats;

	if (argc < 2)
		return (2);
	a.size = argc - 1;
	a.data = malloc(sizeof(int) * (argc - 1));
	if (!a.data)
		return (3);
	b.size = 0;
	b.data = malloc(sizeof(int) * (argc - 1));
	if (!b.data)
		return (free(a.data), 4);
	if (parse_stack(&a, argv + 1) < 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (free(a.data), free(b.data), 5);
	}
	stats = push_swap_checker(&a, &b);
	free(a.data);
	free(b.data);
	if (stats < 0)
		return (6);
	return (stats);
}
