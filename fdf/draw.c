/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:54:46 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/04 09:36:23 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_line_params(t_vertex p0, t_vertex p1, t_var_line *var)
{
	ft_project_3d_to_2d(p0, &var->x0, &var->y0);
	ft_project_3d_to_2d(p1, &var->x1, &var->y1);
	var->dx = abs(var->x1 - var->x0);
	var->dy = abs(var->y1 - var->y0);
	if (var->x0 < var->x1)
		var->sx = 1;
	else
		var->sx = -1;
	if (var->y0 < var->y1)
		var->sy = 1;
	else
		var->sy = -1;
	var->err = var->dx - var->dy;
}

static void	draw_line_step(t_data *data, t_var_line *var, int color)
{
	var->e2 = 2 * var->err;
	if (var->e2 > -var->dy)
	{
		var->err -= var->dy;
		var->x0 += var->sx;
	}
	if (var->e2 < var->dx)
	{
		var->err += var->dx;
		var->y0 += var->sy;
	}
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, var->x0, var->y0, color);
}

void	ft_draw_line_3d(t_data *data, t_vertex p0, t_vertex p1, int color)
{
	t_var_line	var;

	set_line_params(p0, p1, &var);
	while (var.x0 != var.x1 || var.y0 != var.y1)
		draw_line_step(data, &var, color);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, var.x1, var.y1, color);
}

void ft_draw_mesh(t_data *data, t_vertices *vertices, int color, int width, int height, float scale)
{
    t_vertices    *current;
    t_vertices    *next;
    int           x0, y0, x1, y1;
    int           min_x, max_x, min_y, max_y;
    int           center_x, center_y;

    ft_calculate_bounds(vertices, &min_x, &max_x, &min_y, &max_y);
    center_x = (max_x + min_x) / 2;
    center_y = (max_y + min_y) / 2;

    current = vertices;
    while (current)
    {
        // Appliquer l'échelle avant de centrer
        ft_project_3d_to_2d_isometric(*(current->point), &x0, &y0, scale);

        // Appliquer le centrage après l'échelle
        x0 = x0 + (width / 2) - center_x;
        y0 = y0 + (height / 2) - center_y;

        next = current->next_point;
        if (next)
        {
            ft_project_3d_to_2d_isometric(*(next->point), &x1, &y1, scale);

            // Appliquer le centrage après l'échelle
            x1 = x1 + (width / 2) - center_x;
            y1 = y1 + (height / 2) - center_y;

            ft_draw_line_3d(data, *(current->point), *(next->point), color);
        }

        current = current->next_point;
    }
}
