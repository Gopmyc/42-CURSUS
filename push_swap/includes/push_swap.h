/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:25:37 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/10 13:12:02 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdio.h>

/* CHUNK SIZE STRUCT */
typedef struct s_chunk
{
	int				size;
	int				count;
	int				rest;
}				t_chunk;

/* --- UTILES PART --- */
/* Utiles function(s) */
void			ft_error(char *msg);

/* Memory function(s) */
void			*ft_memcalloc(size_t size);

/* --- PARSING PART --- */
ssize_t			ft_fill_stack(t_stack *stack, char **av);

/* --- ALGORITHMES PART --- */
void			sort_small_stack_reverse(t_stack **b, t_stack **a, ssize_t size);
void			sort_small_stack(t_stack **a, t_stack **b, ssize_t size);
void			sort_two(t_stack **a);
void			sort_three(t_stack **a);
void			sort_five(t_stack **a, t_stack **b);
void			push_min_to_b(t_stack **a, t_stack **b, int min);
int				find_min(t_stack *stack);
void			sort_twenty(t_stack **a, t_stack **b, ssize_t size);
void			sort_two_reverse(t_stack **b);
void			sort_three_reverse(t_stack **a, t_stack **b);

/* Base algorithmes function(s) */
int				swap(t_stack **stack);
int				push(t_stack **stack_to, t_stack **stack_from);
int				rotate(t_stack **stack);
int				reverse_rotate(t_stack **stack);

/* Base function(s) */
int				SA(t_stack **stack_a);
int				SB(t_stack **stack_b);
int				SS(t_stack **stack_a, t_stack **stack_b);
int				PA(t_stack **stack_a, t_stack **stack_b);
int				PB(t_stack **stack_a, t_stack **stack_b);
int				RA(t_stack **stack_a);
int				RB(t_stack **stack_b);
int				RR(t_stack **stack_a, t_stack **stack_b);
int				RRA(t_stack **stack_a);
int				RRB(t_stack **stack_b);
int				RRR(t_stack **stack_a, t_stack **stack_b);

/* Radix function */
void			ft_radix(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk);

/* DEBUG PART */
void			ft_debug_stack(t_stack *stack, int chunk_size);

#endif