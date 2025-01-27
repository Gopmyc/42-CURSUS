/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:05:54 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/27 09:07:59 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_small_stack(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

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
