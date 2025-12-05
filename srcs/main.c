/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:06:39 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/05 16:34:33 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (1);
	if (argc == 2 && parse_stack_str(&a, *(argv + 1)) < 0)
		return (2);
	if (argc > 2 && parse_stack_lst(&a, argc - 1, argv + 1) < 0)
		return (3);
	b.size = 0;
	b.data = malloc(sizeof(int) * (a.size));
	if (!b.data)
		return (free(a.data), 4);
	turk_sort_algorithmn(&a, &b);
	free(a.data);
	free(b.data);
	return (0);
}
