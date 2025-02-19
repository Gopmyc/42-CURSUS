/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 06:51:13 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/19 09:58:49 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_fdf	*ft_init(const char *path)
{
	t_fdf			*env;
	char			*title;

	title = ft_strjoin("FdF - ", path);
	env = (t_fdf *)malloc(sizeof(t_fdf));
	if (!env)
		ft_return_error("Malloc error", 1, env);
	env->memory_manager = init_mem_manager();
	env->mlx = mlx_init();
	if (!env->mlx)
		ft_return_error("Graphics part initialization error", 1, env);
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, title);
	if (!env->win)
		ft_return_error("Error initializing window", 1, env);
	free(title);
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (!env->img)
		ft_return_error("Error initializing image", 1, env);
	env->data_addr = mlx_get_data_addr(env->img, &env->bpp, &env->size_line,
			&env->endian);
	env->map = NULL;
	env->camera = NULL;
	return (env);
}

static t_camera	*ft_camera_init(t_fdf *env)
{
	t_camera	*camera;

	camera = (t_camera *)mem_alloc(env->memory_manager, sizeof(t_camera));
	if (!camera)
		ft_return_error("Error initializing camera", 1, env);
	camera->zoom = ft_min(WIDTH / env->map->width / 2,
			HEIGHT / env->map->height / 2);
	camera->x_angle = -0.615472907;
	camera->y_angle = -0.523599;
	camera->z_angle = 0.615472907;
	camera->z_height = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->iso = 1;
	return (camera);
}

static t_map	*ft_map_init(t_fdf *env)
{
	t_map	*map;

	map = (t_map *)mem_alloc(env->memory_manager, sizeof(t_map));
	if (!map)
		ft_return_error("Error initializing map, memory allocation failed", 1,
			env);
	map->height = 0;
	map->width = 0;
	map->array = NULL;
	map->z_max = 0;
	map->z_min = 0;
	return (map);
}

int	main(int argc, char *argv[])
{
	t_fdf			*env;

	env = NULL;
	if (argc == 2)
	{
		env = ft_init(argv[1]);
		env->map = ft_map_init(env);
		ft_check_valid(argv[1], env);
		env->camera = ft_camera_init(env);
		ft_hook_main(env);
		ft_draw(env->map, env);
		mlx_loop(env->mlx);
		ft_close_win(env);
	}
	else
		ft_return_error("Usage incorrect : ./fdf <filename>", 0, env);
}
