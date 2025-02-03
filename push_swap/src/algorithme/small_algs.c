/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:05:54 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/03 11:06:23 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_small_stack(t_stack *stack)
{
	t_stack	*min;
	t_stack	*curr;
	int		a;
	int		b;
	int		c;

	if (stack == NULL || stack->next == NULL)
		return ;
	if (stack->next->next == NULL)
	{
		a = stack->value;
		b = stack->next->value;
		c = stack->next->next->value;
		if (a > b && b < c && a < c)
			sa(&stack);
		else if (a > b && b > c && a > c)
		{
			sa(&stack);
			rra(&stack);
		}
		else if (a > b && b < c && a > c)
			ra(&stack);
		else if (a < b && b > c && a < c)
		{
			sa(&stack);
			ra(&stack);
		}
		else if (a < b && b > c && a > c)
			rra(&stack);
	}
	else
	{
		while (stack != NULL)
		{
			min = stack;
			curr = stack;
			while (curr != NULL)
			{
				if (curr->value < min->value)
					min = curr;
				curr = curr->next;
			}
			if (min != stack)
			{
				while (stack != min)
					ra(&stack);
				sa(&stack);
			}
			stack = stack->next;
		}
	}
}
