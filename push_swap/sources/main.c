/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:26:14 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/23 10:18:24 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"



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
	t_mem_manager	*manager;
	t_stack 		*stack_a;
	t_stack 		*stack_b;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!(argv))
			return(0);
		argc = 0;
		while (argv[argc++])	;
	}
	else
		argv = argv + 1;
	if (check_duplicates(argv))
		ft_error();
	if (check_sorted(argv, 0))
		return (0);
	manager = init_mem_manager();
	if (!(manager))
		return (1);
	stack_a = ft_fill_stack(argv, manager);
	stack_b = NULL;
	start_algo(stack_a, stack_b, argc);
	destroy_mem_manager(manager);
	return (0);
}
