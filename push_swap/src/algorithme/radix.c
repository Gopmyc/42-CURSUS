/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:37:39 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/26 19:36:10 by ghoyaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_find_max_index(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	max = stack->index;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int	ft_find_position(t_stack *stack, int target)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == target)
			break ;
		pos++;
		stack = stack->next;
	}
	return (pos);
}

void	ft_push_back(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;
	int	size;
	int	max;

	while (*stack_b)
	{
		max = ft_find_max_index(*stack_b);
		pos = ft_find_position(*stack_b, max);
		size = ft_lstsize(*stack_b);
		if (pos <= size / 2)
			while ((*stack_b)->index != max)
				rb(stack_b);
		else
			while ((*stack_b)->index != max)
				rrb(stack_b);
		pa(stack_a, stack_b);
	}
}

static int	ft_get_chunk(int size)
{
	int	chunk;

	chunk = size / 5;
	if (size % 5)
		chunk++;
	return (chunk);
}

void	ft_chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	chunk;
	int	current;

	size = ft_lstsize(*stack_a);
	chunk = ft_get_chunk(size);
	current = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= current)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			current++;
		}
		else if ((*stack_a)->index <= current + chunk)
		{
			pb(stack_a, stack_b);
			current++;
		}
		else
			ra(stack_a);
	}
	ft_push_back(stack_a, stack_b);
}
