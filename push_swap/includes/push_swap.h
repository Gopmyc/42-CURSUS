/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:25:37 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/21 10:38:10 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdio.h>

// Commande checker : var="3 4 0 5 6"; ./push_swap $var | ./checker_linux $var
// gere max int en erreur
// Gerre nombres neg si pas deja fait
// Gerre le cas ou il a rien
// Gerre le cas ou il n'a qu'un nombre

typedef struct s_mem_node
{
	void				*address;
	struct s_mem_node	*next;
}	t_mem_node;

typedef struct s_mem_manager
{
	t_mem_node	*head;
}	t_mem_manager;

/* --- UTILES PART --- */
/* Utiles function(s) */
void			ft_error(char *msg);
int				check_sorted(char **av, int order);
int				get_stack_size(t_stack	*stack);
void			print_stack(const char *name, t_stack *stack);
int				check_duplicates(char **argv, int argc);

/* Memory function(s) */
t_mem_manager	*init_mem_manager(void);
void			*mem_alloc(t_mem_manager *manager, size_t size);
void			free_all(t_mem_manager *manager);
void			destroy_mem_manager(t_mem_manager *manager);
void			ft_free_tbl(char **array, size_t j);

/* --- PARSING PART --- */
char			**prepare_arguments(char **av, t_mem_manager *manager);
t_stack			*ft_fill_stack(char **av, t_mem_manager	*manager);

/* Base algorithmes instructions */
int				swap(t_stack **stack);
int				push(t_stack **stack_to, t_stack **stack_from);
int				rotate(t_stack **stack);
int				reverserotate(t_stack **stack);

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