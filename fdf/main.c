/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:32:21 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/04 09:38:44 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
    t_vertices    *vertices;
    t_data        data;

    if (argc == 2)
    {
        data = ft_init_windows(WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
        vertices = get_vertices_list(argv[1]);

        //ft_draw_points_isometric(&data, vertices, 0xFFFFFF, WINDOW_WIDTH, WINDOW_HEIGHT, 1.0);
        ft_draw_mesh(&data, vertices, 0xFFFFFF, WINDOW_WIDTH, WINDOW_HEIGHT, 1000.0);

        mlx_hook(data.win_ptr, 17, 0, ft_close_window, &data);
        mlx_key_hook(data.win_ptr, ft_handle_keypress, &data);
        mlx_loop(data.mlx_ptr);

        ft_free_vertices(vertices);
        ft_free_windows(&data);
    }

    return (EXIT_SUCCESS);
}
