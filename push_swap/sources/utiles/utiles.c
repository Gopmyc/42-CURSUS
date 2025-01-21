/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:39:28 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/21 10:42:02 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_error(char *msg)
{
	while (*msg != '\0')
		write(STDERR_FILENO, msg++, 1);
	write(STDERR_FILENO, "\n", 1);
	exit(-1);
}

int	check_sorted(char **av, int order)
{
	int		i;
	long	prev;
	long	current;

	if (!av || !av[0])
		return (1);
	// TODO : check if the first element is a number or a srting and adjust
	i = 0;
	prev = ft_atol(av[i++]);
	if (prev == LONG_MAX)
		return (0);
	while (av[i])
	{
		if (!ft_isnumber(av[i]))
			return (0);
		current = ft_atol(av[i]);
		if (current == LONG_MAX)
			return (0);
		if ((order == 0 && prev > current)
			|| (order != 0 && prev < current))
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

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int check_duplicates(char **argv, int argc)
{
	for (int i = 1; i < argc - 1; i++)
	{
		for (int j = i + 1; j < argc; j++)
		{
			if (strcmp(argv[i], argv[j]) == 0)
				return (1);
		}
	}
	return (0);
}
