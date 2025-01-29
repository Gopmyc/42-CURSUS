/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:07:36 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/29 08:36:58 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static t_stack	*assign_indices(t_stack *stack, int *sorted, ssize_t size)
{
	t_stack	*head;
	ssize_t	i;

	head = stack;
	while (stack)
	{
		i = 0;
		while (i < size)
		{
			if (stack->value == sorted[i])
			{
				stack->index = i + 1;
				break ;
			}
			i++;
		}
		stack = stack->next;
	}
	return (head);
}

static int	*sort_values(char **av, ssize_t size, t_mem_manager *manager)
{
	t_sort_values	sort;

	sort.values = mem_alloc(manager, size * sizeof(int));
	if (!sort.values)
		return (0);
	sort.i = -1;
	while (++sort.i < size)
		sort.values[sort.i] = ft_atoi(av[sort.i]);
	sort.i = -1;
	while (++sort.i < size - 1)
	{
		sort.j = 0;
		while (sort.j < size - sort.i - 1)
		{
			if (sort.values[sort.j] > sort.values[sort.j + 1])
			{
				sort.tmp = sort.values[sort.j];
				sort.values[sort.j] = sort.values[sort.j + 1];
				sort.values[sort.j + 1] = sort.tmp;
			}
			sort.j++;
		}
	}
	return (sort.values);
}

t_stack	*ft_fill_stack(char **av, t_mem_manager *manager)
{
	t_fill	fill;

	fill = (t_fill){NULL, NULL, NULL, -1, 0, 0, NULL};
	while (av[fill.size])
		fill.size++;
	fill.sorted = sort_values(av, fill.size, manager);
	while (av[++fill.i])
	{
		fill.value = ft_atol(av[fill.i]);
		if ((fill.value > INT_MAX) || (fill.value < INT_MIN))
			return (NULL);
		fill.new_node = mem_alloc(manager, sizeof(t_stack));
		if (!fill.new_node)
			return (NULL);
		fill.new_node->value = (int)fill.value;
		fill.new_node->index = 0;
		fill.new_node->prev = fill.previous;
		fill.new_node->next = NULL;
		if (!fill.stack)
			fill.stack = fill.new_node;
		else
			fill.previous->next = fill.new_node;
		fill.previous = fill.new_node;
	}
	return (assign_indices(fill.stack, fill.sorted, fill.size));
}
