/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:25:37 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/07 09:06:15 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

/* STACK STRUCT */
typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

/* Utiles function(s) */
void			ft_error(char *msg);

/* Base algorithmes function(s) */
int				swap(t_list **stack);
int				push(t_list **stack_to, t_list **stack_from);
int				rotate(t_list **stack);
int				reverse_rotate(t_list **stack);

/* Base function(s) */
int				sa(t_list **stack_a);
int				sb(t_list **stack_b);
int				ss(t_list **stack_a, t_list **stack_b);
int				pa(t_list **stack_a, t_list **stack_b);
int				pb(t_list **stack_a, t_list **stack_b);
int				ra(t_list **stack_a);
int				rb(t_list **stack_b);
int				rr(t_list **stack_a, t_list **stack_b);
int				rra(t_list **stack_a);
int				rrb(t_list **stack_b);
int				rrr(t_list **stack_a, t_list **stack_b);

#endif