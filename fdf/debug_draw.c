/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 08:28:58 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/04 09:28:51 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Visual debugging function */

void ft_draw_points_isometric(t_data *data, t_vertices *vertices, int color, int width, int height, float scale)
{
    t_vertices    *current;
    int           x, y;
    int           min_x, max_x, min_y, max_y;
    int           center_x, center_y;

    ft_calculate_bounds(vertices, &min_x, &max_x, &min_y, &max_y);
    center_x = (max_x + min_x) / 2;
    center_y = (max_y + min_y) / 2;

    current = vertices;
    while (current)
    {
        ft_project_3d_to_2d_isometric(*(current->point), &x, &y, scale);

        x = x + (width / 2) - center_x;
        y = y + (height / 2) - center_y;

        if (x >= 0 && x < width && y >= 0 && y < height)
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);

        current = current->next_point;
    }
}
