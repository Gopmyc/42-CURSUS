/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:39:14 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/19 09:54:28 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	ft_get_height(char *filename, t_fdf *env)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_return_error("open error", 1, env);
	height = 0;
	while (get_next_line(fd, &line, env->memory_manager) >= 0 && *line != '\0')
	{
		height++;
	}
	if (close(fd) == -1)
		ft_return_error("close error", 1, env);
	return (height);
}

static int	ft_get_width(char *filename, t_fdf *env)
{
	int		fd;
	int		width;
	char	*line;
	int		i;

	i = -1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_return_error("open error", 1, env);
	width = 0;
	get_next_line(fd, &line, env->memory_manager);
	if (*line == '\0')
		ft_return_error("invalid map (empty)", 0, env);
	while (line[++i])
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			width++;
	if (close(fd) == -1)
		ft_return_error("close error", 1, env);
	return (width);
}

static void	ft_fill_table(int **n, char *line, int width, t_fdf *env)
{
	char	**num;
	int		i;
	int		j;

	num = ft_split(line, ' ', env->memory_manager);
	i = -1;
	while (num[++i] && i < width)
	{
		n[i] = mem_alloc(env->memory_manager, sizeof(int) * 3);
		if (!n[i])
			ft_return_error("Map error, memmory allocation failed", 1, env);
		n[i][0] = ft_atoi(num[i]);
		j = 0;
		while (num[i][j] && num[i][j] != ',')
			j++;
		if (num[i][j] == ',')
			n[i][1] = ft_atoi_base(&num[i][++j], "0123456789ABCDEF");
		else
			n[i][1] = -1;
	}
	if (i != width || num[i])
		ft_return_error("error: fdf file has irregular width", 0, env);
}

static void	ft_get_z_min_max(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->z_min = map->array[0][0][0];
	map->z_max = map->array[0][0][0];
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->array[i][j][0] < map->z_min)
				map->z_min = map->array[i][j][0];
			if (map->array[i][j][0] > map->z_max)
				map->z_max = map->array[i][j][0];
			j++;
		}
		i++;
	}
}

void	ft_check_valid(char *filename, t_fdf *env)
{
	int		fd;
	char	*line;
	int		i;

	env->map->width = ft_get_width(filename, env);
	env->map->height = ft_get_height(filename, env);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_return_error("Open error", 1, env);
	i = -1;
	env->map->array = mem_alloc(env->memory_manager,
			sizeof(int **) * env->map->height);
	if (!(env->map->array))
		ft_return_error("Map error, memory allocation failed", 1, env);
	while (get_next_line(fd, &line, env->memory_manager) >= 0 && *line != '\0')
	{
		env->map->array[++i] = mem_alloc(env->memory_manager,
				sizeof(int *) * env->map->width);
		if (!(env->map->array[i]))
			ft_return_error("Malloc error", 1, env);
		ft_fill_table(env->map->array[i], line, env->map->width, env);
	}
	ft_get_z_min_max(env->map);
	if (close(fd) == -1)
		ft_return_error("Close error", 1, env);
}
