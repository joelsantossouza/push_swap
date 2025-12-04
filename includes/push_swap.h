/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:03:26 by joesanto          #+#    #+#             */
/*   Updated: 2025/12/03 22:39:43 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

// PARSING
int		parse_stack(size_t size, int stack[size], char **numbers);

// INSTRUCTIONS
void	rotate_a(size_t size_a, int stack_a[size_a]);
void	rotate_b(size_t size_b, int stack_b[size_b]);
void	push_to_a(size_t *size_a, int stack_a[*size_a], size_t *size_b, int stack_b[*size_b]);
void	push_to_b(size_t *size_b, int stack_b[*size_b], size_t *size_a, int stack_a[*size_a]);

// STACK INSERTION
size_t	stack_insertion_finder(int insert, size_t size, int stack[size]);

// SORTING ALGORITHMN
void	turk_algorithmn(size_t size_a, int stack_a[size_a], size_t size_b, int stack_b[size_b]);

#endif
