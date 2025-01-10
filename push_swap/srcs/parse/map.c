/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:07:36 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/10 09:59:39 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_fill_stack(t_stack *stack, char **av)
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
}
