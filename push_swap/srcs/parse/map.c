/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:07:36 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/10 10:44:03 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

ssize_t		ft_fill_stack(t_stack *stack, char **av)
{
	ssize_t	i;
	t_stack	*current;

	i = 0;
	current = stack;
	while (av[i])
	{
		current->value = ft_atoi(av[i]);
		current->index = i;
		if (av[i + 1])
		{
			current->next = ft_memcalloc(sizeof(t_stack));
			current = current->next;
		}
		else
			current->next = NULL;
		i++;
	}
	return (i);
}
