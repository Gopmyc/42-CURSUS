/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 22:21:28 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/12/02 23:27:46 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vertex	*ft_new_vertex(int *x, int *y, int *z)
{
	t_vertex	*v;

	if (!(x) || !(y) || !(z))
		ft_fdf_errors("Invalid data for vertex creation");
	v = (t_vertex *)malloc(sizeof(t_vertex));
	if (!(v))
		ft_fdf_errors("Allocation fails for vertex");
	v->x = (int *)malloc(sizeof(int));
	v->y = (int *)malloc(sizeof(int));
	v->z = (int *)malloc(sizeof(int));
	if (!v->x || !v->y || !v->z)
	{
		free(v->x);
		free(v->y);
		free(v->z);
		free(v);
		ft_fdf_errors("Allocation fails for vertex data");
	}
	*(v->x) = *x;
	*(v->y) = *y;
	*(v->z) = *z;
	return (v);
}

t_vertices	*ft_new_vertices(int *x, int *y, int *z)
{
	t_vertices	*vs;

	if (!(x) || !(y) || !(z))
		ft_fdf_errors("Invalid data for vertices creation");
	vs = (t_vertices *)ft_memcalloc(sizeof(t_vertices));
	if (!(vs))
		ft_fdf_errors("Allocation fails for vertices");
	vs->point = ft_new_vertex(x, y, z);
	return (vs);
}

t_vertex	*ft_add_vertex(t_vertices *vertices_struct, int *x, int *y, int *z)
{
	t_vertex	*new_point;
	t_vertices	*new_node;
	t_vertices	*temp_point;

	new_point = ft_new_vertex(x, y, z);
	new_node = (t_vertices *)malloc(sizeof(t_vertices));
	if (!new_node)
		ft_fdf_errors("Memory allocation failed for new node");
	new_node->point = new_point;
	new_node->next_point = NULL;
	if (!(vertices_struct))
	{
		vertices_struct = ft_new_vertices(x, y, z);
		return (vertices_struct->point);
	}
	if (!(vertices_struct->point))
	{
		vertices_struct->point = new_point;
		return (new_point);
	}
	temp_point = vertices_struct;
	while (temp_point->next_point)
	{
		temp_point = temp_point->next_point;
	}
	temp_point->next_point = new_node;
	return (new_point);
}

void ft_free_vertices(t_vertices *vertices)
{
    t_vertices *current = vertices;
    t_vertices *next;

    while (current)
    {
        next = current->next_point;
        free(current->point->x);
        free(current->point->y);
        free(current->point->z);
        free(current->point);
        free(current);
        current = next;
    }
}

