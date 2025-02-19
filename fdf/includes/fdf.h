/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 06:58:08 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/19 09:11:47 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "gc.h"
# include "gnl.h"
# include "libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 600

# define ESCAPE 65307

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
	int	reverse;
}				t_point;

typedef struct s_map
{
	int	height;
	int	width;
	int	***array;
	int	z_max;
	int	z_min;
}				t_map;

typedef struct s_camera
{
	int		zoom;
	double	x_angle;
	double	y_angle;
	double	z_angle;
	float	z_height;
	int		x_offset;
	int		y_offset;
	int		iso;
}				t_camera;

typedef struct s_fdf
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_addr;
	int				bpp;
	int				size_line;
	int				endian;
	int				steep;
	t_map			*map;
	t_camera		*camera;
	t_mem_manager	*memory_manager;
}				t_fdf;

/* ---- DATA PARTS ---- */

/* Parse map functions : */
void			ft_check_valid(char *filename, t_fdf *env);

/* ---- DRAW PARTS ---- */

/* Draw line functions : */
void			ft_draw_line(t_point s, t_point e, t_fdf *env);

/* Draw main functions : */
void			ft_draw(t_map *map, t_fdf *env);

/* ---- INPUTS PARTS ---- */

/* Hooks functions : */
void			ft_hook_main(t_fdf *env);
int				ft_close_win(void *params);

/* Keys functions : */
int				ft_key_press(int keycode, void *params);

/* ---- MATHS PARTS ---- */

/* Maths matrices functions :*/
t_point			project(int x, int y, t_fdf *env);

/* Maths utiles functions : */
float			ft_abs(float n);
int				ft_ipart(float n);
float			ft_fpart(float n);
float			ft_rfpart(float n);

/* Utils functions : */
int				ft_min(int a, int b);
int				get_default_color(int z, t_map *map);
void			ft_return_error(const char *err_msg, int system_function,
					t_fdf *env);
void			ft_put_pixel(t_fdf *env, int x, int y, int color);

#endif