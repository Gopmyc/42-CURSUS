/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:39:08 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/10 09:42:39 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_debug_stack(t_stack *stack)
{
	t_stack	*current;
	ssize_t	i;

	current = stack;
	i = 0;
	printf("---- Stack Debug ----\n");
	while (current)
	{
		printf("Node %zd:\n", i);
		printf("  Value: %d\n", current->value);
		printf("  Index: %d\n", current->index);
		if (current->next)
			printf("  Next: %p\n", (void *)current->next);
		else
			printf("  Next: NULL\n");
		current = current->next;
		i++;
	}
	printf("---------------------\n");
}
