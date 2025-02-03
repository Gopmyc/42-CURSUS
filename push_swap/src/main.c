/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:26:14 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/03 10:59:19 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	free_split(char **array)
{
	size_t	i;

	if (!array)
		return (0);
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}

static int	ft_count_size(char **av)
{
	int	i;

	i = 0;
	while (av[i++])
		;
	return (i);
}

static void	start_algo(t_stack *stack_a, t_stack *stack_b, int argc)
{
	if (!(stack_a))
		ft_error();
	else if (argc <= 10)
		sort_small_stack(stack_a);
	else
		ft_radix(&stack_a, &stack_b);
}

int	main(int argc, char **argv)
{
	t_main	main_struc;

	if (argc < 2)
		return (0);
	main_struc.is_alloc = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (0);
		main_struc.is_alloc = 1;
		argc = ft_count_size(argv);
	}
	else
		argv++;
	if (check_duplicates(argv) || check_sorted(argv, 0))
		return (main_struc.is_alloc && free_split(argv), 0);
	main_struc.manager = init_mem_manager();
	main_struc.stack_a = ft_fill_stack(argv, main_struc.manager);
	main_struc.stack_b = NULL;
	if (main_struc.is_alloc)
		free_split(argv);
	start_algo(main_struc.stack_a, main_struc.stack_b, --argc);
	return (destroy_mem_manager(main_struc.manager));
}
