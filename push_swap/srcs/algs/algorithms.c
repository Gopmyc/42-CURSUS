/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:29:09 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/10 15:21:32 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void sort_two(t_stack **a)
{
    if ((*a)->value > (*a)->next->value)
        SA(a); // Échange les deux éléments
}

void sort_three(t_stack **a)
{
    int top = (*a)->value;
    int middle = (*a)->next->value;
    int bottom = (*a)->next->next->value;

    if (top > middle && middle > bottom)
    {
        SA(a);
        RRA(a);
    }
    else if (top > bottom && bottom > middle)
        RA(a);
    else if (middle > top && top > bottom)
        RRA(a);
    else if (middle > bottom && bottom > top)
    {
        SA(a);
        RA(a);
    }
    else if (bottom > top && top > middle)
        SA(a);
}

void sort_small_stack_reverse(t_stack **b, t_stack **a, ssize_t size)
{
    if (size == 2)
        sort_two_reverse(b);
    else if (size == 3)
        sort_three_reverse(a, b);
}

void sort_small_stack(t_stack **a, t_stack **b, ssize_t size)
{
    if (size == 2)
        sort_two(a);
    else if (size == 3)
        sort_three(a);
    else if (size <= 5)
        sort_five(a, b);
    else
        sort_twenty(a, b, size);
}

void sort_five(t_stack **a, t_stack **b)
{
    int min;
    int second_min;

    min = find_min(*a);
    push_min_to_b(a, b, min);

    second_min = find_min(*a);
    push_min_to_b(a, b, second_min);

    sort_three(a); // Trie les 3 éléments restants

    PA(a, b); // Réinsère le deuxième plus petit
    PA(a, b); // Réinsère le plus petit
}

void push_min_to_b(t_stack **a, t_stack **b, int min)
{
    while ((*a)->value != min)
        RA(a);
    PB(a, b);
}

int find_min(t_stack *stack)
{
    int min = stack->value;

    while (stack)
    {
        if (stack->value < min)
            min = stack->value;
        stack = stack->next;
    }
    return (min);
}

void sort_twenty(t_stack **a, t_stack **b, ssize_t size)
{
    int half_size = size / 2;
    int i = 0;

    // Pousse la moitié inférieure dans `b`
    while (i++ < half_size)
        PB(a, b); 

    // Trie les 10 éléments restants dans `a` et dans `b`
    sort_small_stack(a, b, half_size);  // Trie les 10 éléments restants dans `a`
    sort_small_stack_reverse(b, a, half_size); // Trie les 10 éléments dans `b`

    // Réinsère tout de `b` dans `a`
    while (*b) 
    {
        PA(a, b); // Réinsère l'élément du haut de b dans a
    }
}

void sort_two_reverse(t_stack **b)
{
    if ((*b)->value < (*b)->next->value)
        SB(b); // Échange les deux éléments
}

void sort_three_reverse(t_stack **a, t_stack **b)
{
    int top = (*b)->value;
    int middle = (*b)->next->value;
    int bottom = (*b)->next->next->value;

    if (top < middle && middle < bottom)
    {
        SB(b);
        RR(a, b);
    }
    else if (top < bottom && bottom < middle)
        RB(b);
    else if (middle < top && top < bottom)
        RR(a, b);
    else if (middle < bottom && bottom < top)
    {
        SB(b);
        RB(b);
    }
    else if (bottom < top && top < middle)
        SB(b);
}

