/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:05:54 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/26 21:00:39 by ghoyaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	get_min(t_stack **stack, int val)
{
	t_stack	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

void	process_sort_3(t_stack **stack_a, t_stack *head,
	int min, int next_min)
{
	if (head->index == min && head->next->index != next_min)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			sa(stack_a);
		else
			rra(stack_a);
	}
	else
	{
		if (head->next->index == min)
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}

void	sort_3(t_stack **stack_a)
{
	t_stack	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (is_sorted(stack_a))
		return ;
	process_sort_3(stack_a, head, min, next_min);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}
