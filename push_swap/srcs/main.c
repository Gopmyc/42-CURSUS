/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:26:14 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/13 13:43:34 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	start_algo(t_stack *stack_a, t_stack *stack_b, int argc)
{
	if (argc - 1 <= 3)
		sort_small_stack(stack_a);
	ft_radix(&stack_a, &stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (argc >= 2)
	{
		stack_a = ft_memcalloc(sizeof(t_stack));
		stack_b = ft_memcalloc(sizeof(t_stack));
		stack_size = ft_fill_stack(stack_a, argv + 1);
		if (check_sorted(stack_a, 0))
			return (0);
		start_algo(stack_a, stack_b, argc);
		//print_stack("STACK A", stack_a);
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
	}
	else
		ft_error("Erreur d'argument\n");
	return (0);
}
