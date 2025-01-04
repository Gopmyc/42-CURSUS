/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:21:34 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/11/16 01:57:42 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_vertices(t_vertices *vertices)
{
	t_vertices	*current;

	current = vertices;
	while (current)
	{
		ft_printf("Vertex: x = %d, y = %d, z = %d\n",
			*(current->point->x), *(current->point->y), *(current->point->z));
		current = current->next_point;
	}
}
