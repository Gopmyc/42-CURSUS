/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:39:56 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/26 08:58:17 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	ft_close_win(void *params)
{
	t_fdf	*env;

	env = (t_fdf *)params;
	if (env->img)
		mlx_destroy_image(env->mlx, env->img);
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	if (env->mlx)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
	}
	if (env->memory_manager)
		destroy_mem_manager(env->memory_manager);
	free(env);
	exit(0);
}

void	ft_hook_main(t_fdf *env)
{
	mlx_key_hook(env->win, ft_key_press, env);
	mlx_mouse_hook(env->win, ft_mouse, env);
	mlx_hook(env->win, 17, 0, ft_close_win, env);
}
