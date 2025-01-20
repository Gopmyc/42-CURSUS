/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:18:55 by pthuilli          #+#    #+#             */
/*   Updated: 2025/01/20 10:45:08 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	swap(t_stack **stack)
{
	t_stack	*head;
	t_stack	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	tmp_val = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	head->next = next->next;
	if (next->next)
		next->next->prev = head;
	next->prev = NULL;
	*stack = next;
	return (0);
}

int	push(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*tmp;
	t_stack	*head_to;
	t_stack	*head_from;

	if (ft_lstsize(*stack_from) == 0)
		return (-1);
	head_from = *stack_from;
	tmp = head_from;
	*stack_from = head_from->next;
	if (*stack_to == NULL)
	{
		*stack_to = tmp;
		tmp->next = NULL;
		tmp->prev = NULL;
	}
	else
	{
		head_to = *stack_to;
		*stack_to = tmp;
		tmp->next = head_to;
		tmp->prev = NULL;
		head_to->prev = tmp;
	}
	return (0);
}

int	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	head->prev = tail;
	tail->next = head;
	return (0);
}

int	reverserotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	tail->prev = NULL;
	return (0);
}
