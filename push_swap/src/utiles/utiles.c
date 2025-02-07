/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:39:28 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/27 09:07:59 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(-1);
	return (1); 
}

int	check_sorted(char **av, int order)
{
	int		i;
	long	prev;
	long	current;

	if (!av || !av[0])
		return (1);
	i = 0;
	prev = ft_atol(av[i++]);
	if (prev > INT_MAX || prev < INT_MIN)
		ft_error();
	while (av[i])
	{
		if (!ft_isnumber(av[i]))
			ft_error();
		current = ft_atol(av[i]);
		if (current > INT_MAX || current < INT_MIN)
			ft_error();
		if ((order == 0 && prev > current) || (order != 0 && prev < current))
			return (0);
		prev = current;
		i++;
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

int	check_duplicates(char **argv)
{
	int	i;
	int	j;
	int	current;
	int	checker;

	i = 0;
	while (argv[i])
	{
		current = atoi(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			checker = atoi(argv[j]);
			if (current == checker)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
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
