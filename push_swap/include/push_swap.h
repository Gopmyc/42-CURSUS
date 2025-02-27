/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:25:37 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/26 21:06:02 by ghoyaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdio.h>

// Commande checker : var="3 4 0 5 6"; ./push_swap $var | ./checker_linux $var
// gere max int en erreur
// Gerre nombres neg si pas deja fait : FAIT
// Gerre le cas ou il a rien : FAIT
// Gerre le cas ou il n'a qu'un nombre : FAIT

typedef struct s_mem_node
{
	void				*address;
	struct s_mem_node	*next;
}	t_mem_node;

typedef struct s_mem_manager
{
	t_mem_node	*head;
}	t_mem_manager;

typedef struct s_main
{
	t_mem_manager	*manager;
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				is_alloc;
}	t_main;

typedef struct s_sort_values
{
	int		*values;
	int		tmp;
	int		i;
	int		j;
}	t_sort_values;

typedef struct s_fill
{
	t_stack		*stack;
	t_stack		*previous;
	int			*sorted;
	ssize_t		i;
	int			size;
	long		value;
	t_stack		*new_node;
}	t_fill;

/* --- UTILES PART --- */
/* Utiles function(s) */
int				ft_error(void);
int				check_sorted(char **av, int order);
int				get_stack_size(t_stack	*stack);
int				check_duplicates(char **argv);
int				is_sorted(t_stack **stack);
int				get_distance(t_stack **stack, int index);

/* Memory function(s) */
t_mem_manager	*init_mem_manager(void);
void			*mem_alloc(t_mem_manager *manager, size_t size);
void			free_all(t_mem_manager *manager);
int				destroy_mem_manager(t_mem_manager *manager);
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
int				ft_find_max_index(t_stack *stack);
int				ft_find_position(t_stack *stack, int target);
void			ft_push_back(t_stack **stack_a, t_stack **stack_b);
void			ft_chunk_sort(t_stack **stack_a, t_stack **stack_b);

/* Small Algo, for 1 to 3 elements */
void			simple_sort(t_stack **stack_a, t_stack **stack_b);
int				get_min(t_stack **stack, int val);
void			process_sort_3(t_stack **stack_a, t_stack *head,
					int min, int next_min);
void			sort_3(t_stack **stack_a);
void			sort_4(t_stack **stack_a, t_stack **stack_b);
void			sort_5(t_stack **stack_a, t_stack **stack_b);

#endif