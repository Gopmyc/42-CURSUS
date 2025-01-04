/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:53:17 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/12/02 23:35:39 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	ft_init_windows(unsigned int width, unsigned int height, char *name)
{
	t_data	data;

	if (!(width) || !(height) || !(name))
		ft_fdf_errors("Invalid data for window initialization");
	data.mlx_ptr = mlx_init();
	if (!(data.mlx_ptr))
		ft_fdf_errors("Framework initialization error");
	data.win_ptr = mlx_new_window(data.mlx_ptr,
			width, height, name);
	if (data.win_ptr == NULL)
		ft_fdf_errors("Window initialization error");
	return (data);
}

int	ft_close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

int	ft_handle_keypress(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		ft_close_window(data);
	return (0);
}

void	ft_free_windows(t_data *data)
{
    if (data)
    {
        if (data->win_ptr)
            mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        if (data->mlx_ptr)
            mlx_destroy_display(data->mlx_ptr);
        free(data);
    }
}

