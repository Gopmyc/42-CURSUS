/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthuilli <pthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:05:54 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/17 17:36:30 by pthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
