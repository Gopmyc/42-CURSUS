/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:26:14 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/21 11:39:44 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"



static void	start_algo(t_stack *stack_a, t_stack *stack_b, int i)
{
	if (i == 3)
		sa(&stack_a);
	else if (i <= 3)
		sort_small_stack(stack_a);
	else
		ft_radix(&stack_a, &stack_b);
}

int	main(int argc, char **argv)
{
	t_mem_manager	*manager;
	t_stack 		*stack_a;
	t_stack 		*stack_b;

	int i = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return(0);
		while(argv[i++]) ;
	}
	if (check_duplicates(argv, 0))
		ft_error("Error: Duplicate values found");
	if (check_sorted(argv + 1, 0))
		return (0);
	manager = init_mem_manager();
	if (!(manager))
		return (1);
	stack_a = ft_fill_stack(argv + 1, manager);
	stack_b = NULL;
	start_algo(stack_a, stack_b, i);
	destroy_mem_manager(manager);
	return (0);
}
