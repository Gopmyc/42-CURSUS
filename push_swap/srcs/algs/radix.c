/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:37:39 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/10 12:55:53 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
	CHUNK 1 :
	678
	66788
	34
	32
	7
	9
	56
	6
	546
	17789

	CHUNK 2 :
	87
	32
	76
	89
	45
	5686
	56
	65
	6576
	1
*/

static void	ft_tri_chunk(int size, t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;
	int		range_start;
	int		range_end;

	range_start = stack_a->index;
	range_end = range_start + size;
	while (stack_a)
	{
		current = stack_a;
		if (current->index >= range_start && current->index < range_end)
		{
			if (current->index == range_end - 1)
				PA(&stack_a, &stack_b);
			else
			{
				while (stack_a && stack_a->index != range_end - 1)
				{
					if (stack_a->index > range_end - 1)
						RA(&stack_a);
					else
						RRA(&stack_a);
				}
				PB(&stack_a, &stack_b);
			}
		}
		stack_a = stack_a->next;
	}
}

void	ft_radix(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk)
{
	int	i;
	int	range_start;
	int	range_end;

	i = 0;
	while (i < chunk->count)
	{
		range_start = i * chunk->size;
		range_end = range_start + chunk->size;
		if (i == chunk->count - 1)
			range_end = range_start + chunk->rest;
		ft_tri_chunk(range_end - range_start, stack_a, stack_b);
		i++;
	}
}
