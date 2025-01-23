/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:07:36 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/23 10:18:44 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
	if (!values)
		ft_error();

	i = 0;
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

t_stack	*ft_fill_stack(char **av, t_mem_manager	*manager)
{
	t_stack	*stack;
	t_stack	*previous;
	int		*sorted;
	ssize_t	i;
	int		size;

	stack = NULL;
	previous = NULL;
	i = 0;
	size = 0;
	while (av[size])
		size++;
	sorted = sort_values(av, size, manager);
	if (!sorted)
		ft_error();
	while (av[i])
	{
		t_stack *new_node = mem_alloc(manager, sizeof(t_stack));
		if (!new_node)
			ft_error();
		new_node->value = ft_atoi(av[i]);
		new_node->index = 0;
		new_node->prev = previous;
		new_node->next = NULL;

		if (!stack)
			stack = new_node;
		else
			previous->next = new_node;
		previous = new_node;
		i++;
	}
	if (stack)
		assign_indices(stack, sorted, size);
	return (stack);
}
