/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:26:14 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/10 09:44:42 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc >= 2)
	{
		stack_a = ft_memcalloc(sizeof(t_stack));
		stack_b = ft_memcalloc(sizeof(t_stack));
		ft_fill_stack(stack_a, argv + 1);
		ft_debug_stack(stack_a);
	}
	else
		ft_error("Erreur d'argument\n");
	return (0);
}
