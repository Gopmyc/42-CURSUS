/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:07:36 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/27 09:29:11 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	assign_indices(t_stack *stack, int *sorted, ssize_t size)
{
	ssize_t	i;

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
}

static int	*sort_values(char **av, ssize_t size, t_mem_manager	*manager)
{
	int		*values;
	ssize_t	i;
	ssize_t	j;
	int		tmp;

	values = mem_alloc(manager, size * sizeof(int));
	i = 0;
	if (!values)
		return (0);
	while (i < size)
	{
		values[i] = ft_atoi(av[i]);
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (values[j] > values[j + 1])
			{
				tmp = values[j];
				values[j] = values[j + 1];
				values[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (values);
}

t_stack	*ft_fill_stack(char **av, t_mem_manager *manager)
{
	t_fill fill = {NULL, NULL, NULL, 0, 0, 0, NULL};

	while (av[fill.size])
		fill.size++;
	fill.sorted = sort_values(av, fill.size, manager);
	if (!fill.sorted)
		return (NULL);
	while (av[fill.i])
	{
		fill.value = ft_atol(av[fill.i]);
		if (fill.value > INT_MAX || fill.value < INT_MIN)
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
		fill.i++;
	}
	assign_indices(fill.stack, fill.sorted, fill.size);
	return (fill.stack);
}
