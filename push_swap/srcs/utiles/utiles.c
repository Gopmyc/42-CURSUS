/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:39:28 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/15 10:49:13 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_error(char *msg)
{
	write(STDERR_FILENO, "PUSH SWAP : ", 12);
	while (*msg != '\0')
		write(STDERR_FILENO, msg++, 1);
	write(STDERR_FILENO, "\n", 1);
	exit(-1);
}

int	check_sorted(t_stack *stack, int order)
{
	t_stack	*current;

	if (!stack)
		return (1);
	current = stack;
	while (current->next)
	{
		if ((order == 0 && current->value > current->next->value)
			|| (order != 0 && current->value < current->next->value))
			return (0);
		current = current->next;
	}
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

void print_stack(const char *name, t_stack *stack)
{
    t_stack *current = stack;

    printf("Stack %s:\n", name);
    while (current)
    {
        printf("Value: %d, Index: %d\n", current->value, current->index);
        current = current->next;
    }
    printf("\n");
}
