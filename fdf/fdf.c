/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:51:03 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/04 09:20:44 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vertices	*get_vertices_list(char	*file)
{
	t_vertices	*vertices_list;
	char		*line;
	int			fd;

    vertices_list = ft_new_vertices(&(int){0}, &(int){0}, &(int){0});
    fd = open(file, O_RDONLY);
    if (fd < 0)
		ft_fdf_errors("Error opening file");
    while ((line = get_next_line(fd)) != NULL)
    {
        char *ptr = line;
        while (*ptr)
        {
            int *pz = get_next_number(&ptr, ' ');
            if (pz == NULL)
                break;
            ft_add_vertex(vertices_list, vertices_list->point->x, vertices_list->point->y, pz);
            (*(vertices_list->point->x))++;
        }
        free(line);
        *(vertices_list->point->x) = 0;
        (*(vertices_list->point->y))++;
    }
    close(fd);
	return (vertices_list);
}
