/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:25:37 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/13 13:37:17 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdio.h>

// Commande checker : var="3 4 0 5 6"; ./push_swap $var | ./checker_linux $var

/* --- UTILES PART --- */
/* Utiles function(s) */
void			ft_error(char *msg);
int				check_sorted(t_stack *stack, int order);
int				get_stack_size(t_stack	*stack);
void			print_stack(const char *name, t_stack *stack);

/* Memory function(s) */
void			*ft_memcalloc(size_t size);
void			ft_free_stack(t_stack *stack);

/* --- PARSING PART --- */
ssize_t			ft_fill_stack(t_stack *stack, char **av);

/* Base algorithmes instructions */
int				swap(t_stack **stack);
int				push(t_stack **stack_to, t_stack **stack_from);
int				rotate(t_stack **stack);
int				reverseRotate(t_stack **stack);

int				sa(t_stack **stack_a);
int				sb(t_stack **stack_b);
int				ss(t_stack **stack_a, t_stack **stack_b);
int				pa(t_stack **stack_a, t_stack **stack_b);
int				pb(t_stack **stack_b, t_stack **stack_a);
int				ra(t_stack **stack_a);
int				rb(t_stack **stack_b);
int				rr(t_stack **stack_a, t_stack **stack_b);
int				rra(t_stack **stack_a);
int				rrb(t_stack **stack_b);
int				rrr(t_stack **stack_a, t_stack **stack_b);

/* Radix function */
void			ft_radix(t_stack **stack_a, t_stack **stack_b);

/* Small Algo, for 1 to 3 elements */
void			sort_small_stack(t_stack *stack);

#endif