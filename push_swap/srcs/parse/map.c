/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:07:36 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/15 10:55:01 by ghoyaux          ###   ########.fr       */
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
				break;
			}
			i++;
		}
		stack = stack->next;
	}
}

static int	*sort_values(char **av, ssize_t size)
{
	int		*values;
	ssize_t	i, j;
	int		tmp;

	values = malloc(size * sizeof(int));
	if (!values)
		ft_error("Erreur d'allocation mémoire");
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

ssize_t	ft_fill_stack(t_stack **stack, char **av)
{
	ssize_t	i, count;
	t_stack	*current, *new_node;
	int		*sorted;

	count = 0;
	while (av[count])
		count++;
	sorted = sort_values(av, count);
	i = 0;
	*stack = ft_memcalloc(sizeof(t_stack));
	if (!*stack)
		ft_error("Erreur d'allocation mémoire");
	current = *stack;
	while (av[i])
	{
		current->value = ft_atoi(av[i]);
		if (av[i + 1])
		{
			new_node = ft_memcalloc(sizeof(t_stack));
			if (!new_node)
				ft_error("Erreur d'allocation mémoire");
			current->next = new_node;
			current = new_node;
		}
		else
			current->next = NULL;
		i++;
	}
	assign_indices(*stack, sorted, count);
	free(sorted);
	return (count);
}
