/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:25:37 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/10 09:46:01 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdio.h>

/* --- UTILES PART --- */
/* Utiles function(s) */
void			ft_error(char *msg);

/* Memory function(s) */
void			*ft_memcalloc(size_t size);

/* --- PARSING PART --- */
void			ft_fill_stack(t_stack *stack, char **av);

/* --- ALGORITHMES PART --- */
/* Base algorithmes function(s) */
int				swap(t_stack **stack);
int				push(t_stack **stack_to, t_stack **stack_from);
int				rotate(t_stack **stack);
int				reverse_rotate(t_stack **stack);

/* Base function(s) */
int				sa(t_stack **stack_a);
int				sb(t_stack **stack_b);
int				ss(t_stack **stack_a, t_stack **stack_b);
int				pa(t_stack **stack_a, t_stack **stack_b);
int				pb(t_stack **stack_a, t_stack **stack_b);
int				ra(t_stack **stack_a);
int				rb(t_stack **stack_b);
int				rr(t_stack **stack_a, t_stack **stack_b);
int				rra(t_stack **stack_a);
int				rrb(t_stack **stack_b);
int				rrr(t_stack **stack_a, t_stack **stack_b);

/* DEBUG PART */
void			ft_debug_stack(t_stack *stack);

#endif