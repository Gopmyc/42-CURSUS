/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:39:28 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/26 19:01:41 by ghoyaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
				ft_error();
			j++;
		}
		i++;
	}
	return (0);
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
