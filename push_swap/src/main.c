/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:26:14 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/27 09:33:42 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	free_split(char **array)
{
	size_t	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	start_algo(t_stack *stack_a, t_stack *stack_b, int argc)
{
	if (argc == 3)
		sa(&stack_a);
	else if (argc <= 3)
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
	}
	else
		argv++;
	if (check_duplicates(argv) || check_sorted(argv, 0))
	{
		if (main_struc.is_alloc)
			free_split(argv);
		return (0);
	}
	// ERROR > Show ARGV when arguments are surrounded by quotes or not
	main_struc.manager = init_mem_manager();
	if (!(main_struc.manager))
		ft_error();
	main_struc.stack_a = ft_fill_stack(argv, main_struc.manager);
	main_struc.stack_b = NULL;
	if (main_struc.is_alloc)
		free_split(argv);
	if (!(main_struc.stack_a))
		ft_error();
	start_algo(main_struc.stack_a, main_struc.stack_b, argc);
	destroy_mem_manager(main_struc.manager);
	return (0);
}
