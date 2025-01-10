/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:26:14 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/10 14:40:24 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	t_chunk	*chunk;

	chunk = (t_chunk *)ft_memcalloc(sizeof(t_chunk));
	chunk->size = 20;
	if (argc >= 2)
	{
		stack_a = ft_memcalloc(sizeof(t_stack));
		stack_b = ft_memcalloc(sizeof(t_stack));
		stack_size = ft_fill_stack(stack_a, argv + 1);
		if (stack_size >= (chunk->size * 2))
		{
			chunk->count = (stack_size / chunk->size);
			chunk->rest = stack_size - (chunk->count * chunk->size);
			ft_radix(stack_a, stack_b, chunk);
			ft_debug_stack(stack_a, chunk->size);
			printf(" ---------- STACK B ---------- ");
			ft_debug_stack(stack_b, chunk->size);
		}
		else
		{
			sort_twenty(&stack_a, &stack_b, stack_size);
			ft_debug_stack(stack_a, chunk->size);
			printf(" ---------- STACK B ---------- ");
			ft_debug_stack(stack_b, chunk->size);
		}
		//ft_debug_stack(stack_a);
	}
	else
		ft_error("Erreur d'argument\n");
	return (0);
}
