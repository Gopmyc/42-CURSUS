/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:39:08 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/10 12:56:36 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_debug_stack(t_stack *stack, int chunk_size)
{
	t_stack	*current;
	int		i;
	int		j;

	current = stack;
	i = 0;
	j = 0;
	printf("---- Stack Debug ----\n");
	while (current)
	{
		if (i == chunk_size)
		{
			printf("Chunk %d :\n", j);
			j++;
		}
		printf("\tNode %d :\n", i);
		printf("\t\tValue: %d\n", current->value);
		printf("\t\tIndex: %d\n", current->index);
		if (current->next)
			printf("  Next: %p\n", (void *)current->next);
		else
			printf("  Next: NULL\n");
		current = current->next;
		i++;
	}
}
