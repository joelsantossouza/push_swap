/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 22:57:38 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/05 16:13:00 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

static inline
int	exec_instruction(const char *name, t_stack *a, t_stack *b)
{
	if (ft_strcmp(name, "sa\n") == 0)
		return (swap_top("", a), 0);
	if (ft_strcmp(name, "sb\n") == 0)
		return (swap_top("", b), 0);
	if (ft_strcmp(name, "ss\n") == 0)
		return (sswap_top("", a, b), 0);
	if (ft_strcmp(name, "pa\n") == 0)
		return (push_to("", a, b));
	if (ft_strcmp(name, "pb\n") == 0)
		return (push_to("", b, a));
	if (ft_strcmp(name, "ra\n") == 0)
		return (rotate("", a, 1));
	if (ft_strcmp(name, "rb\n") == 0)
		return (rotate("", b, 1));
	if (ft_strcmp(name, "rr\n") == 0)
		return (rrotate("", a, b, 1));
	if (ft_strcmp(name, "rra\n") == 0)
		return (reverse_rotate("", a, 1));
	if (ft_strcmp(name, "rrb\n") == 0)
		return (reverse_rotate("", b, 1));
	if (ft_strcmp(name, "rrr\n") == 0)
		return (rreverse_rotate("", a, b, 1));
	return (-1);
}

int	push_swap_checker(t_stack *a, t_stack *b)
{
	char	*line;

	line = 0;
	if (ft_getline(&line, STDIN_FILENO) < 0)
		return (-1);
	while (line)
	{
		if (exec_instruction(line, a, b) < 0)
			return (error(), free(line), -1);
		if (ft_getline(&line, STDIN_FILENO) < 0)
			return (-1);
	}
	if (!is_sorted(a->data, a->size) || b->size > 0)
	{
		write(STDOUT_FILENO, "KO\n", 3);
		return (1);
	}
	write(STDOUT_FILENO, "OK\n", 3);
	return (0);
}
