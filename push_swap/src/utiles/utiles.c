/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:39:28 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/26 19:02:36 by ghoyaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(-1);
	return (1);
}

int	get_stack_size(t_stack	*stack)
{
	t_stack	*current;
	int		size;
	int		max_index;

	current = stack;
	size = 0;
	max_index = 0;
	while (current)
	{
		if (current->index > max_index)
			max_index = current->index;
		size++;
		current = current->next;
	}
	return (size);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	get_distance(t_stack **stack, int index)
{
	t_stack	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}
