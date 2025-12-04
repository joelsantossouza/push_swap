/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 22:57:38 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/04 23:23:30 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline
int	exec_instruction(const char *name, t_stack *a, t_stack *b)
{
	if (ft_strcmp(name, "sa\n") == 0)
		return (sa(a), 0);
	if (ft_strcmp(name, "sb\n") == 0)
		return (sb(b), 0);
	if (ft_strcmp(name, "ss\n") == 0)
		return (ss(a, b), 0);
	if (ft_strcmp(name, "pa\n") == 0)
		return (pa(a, b));
	if (ft_strcmp(name, "pb\n") == 0)
		return (pb(a, b));
	if (ft_strcmp(name, "ra\n") == 0)
		return (ra(a));
	if (ft_strcmp(name, "rb\n") == 0)
		return (rb(b));
	if (ft_strcmp(name, "rr\n") == 0)
		return (rr(a, b));
	if (ft_strcmp(name, "rra\n") == 0)
		return (rra(a));
	if (ft_strcmp(name, "rrb\n") == 0)
		return (rrb(b));
	if (ft_strcmp(name, "rrr\n") == 0)
		return (rrr(a, b));
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
		{
			write(STDERR_FILENO, "Error\n", 6);
			return (free(line), -1);
		}
		if (ft_getline(&line, STDIN_FILENO) < 0)
			return (-1);
	}
	if (!is_sort(a) || b->size > 0)
	{
		write(STDOUT_FILENO, "KO\n", 3);
		return (0);
	}
	write(STDOUT_FILENO, "OK\n", 3);
	return (1);
}
