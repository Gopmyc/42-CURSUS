/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:54:44 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/04 09:34:06 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <errno.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define CAMERA_DIST 5
# define ESC_KEY 65307
# define M_PI 3.14159265358979323846

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

typedef struct s_vertex
{
	int	*x;
	int	*y;
	int	*z;
}	t_vertex;

typedef struct s_vertices
{
	t_vertex			*point;
	struct s_vertices	*next_point;
}	t_vertices;

typedef struct s_var_line
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	err;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	e2;
}	t_var_line;

/* Declarations of memory function */
void		*ft_memcalloc(size_t size);

/* Declarations of utils function */
void		ft_project_3d_to_2d(t_vertex p, int *x_proj, int *y_proj);
void		ft_project_3d_to_2d_isometric(t_vertex p, int *x_proj, int *y_proj, float scale);
void		ft_fdf_errors(char *s);
int			*get_next_number(char **str, char separator);
void		ft_calculate_bounds(t_vertices *vertices, int *min_x, int *max_x, int *min_y, int *max_y);

/* Declarations of vertices function */
t_vertex	*ft_new_vertex(int *x, int *y, int *z);
t_vertices	*ft_new_vertices(int *x, int *y, int *z);
t_vertex	*ft_add_vertex(t_vertices *vertices_struct,
				int *x, int *y, int *z);
void		ft_free_vertices(t_vertices *vertices);

/* Declarations of debug function */
void		ft_print_vertices(t_vertices *vertices);

/* Declarations of debug draw function */
void		ft_draw_points_isometric(t_data *data, t_vertices *vertices, int color, int width, int height, float scale);

/* Declarations of events function */
t_data		ft_init_windows(unsigned int width,
				unsigned int height, char *name);
int			ft_close_window(t_data *data);
int			ft_handle_keypress(int keycode, t_data *data);
void		ft_free_windows(t_data *data);

/* Declarations of draw function */
void		ft_draw_line_3d(t_data *data, t_vertex p0, t_vertex p1, int color);
void		ft_draw_mesh(t_data *data, t_vertices *vertices, int color, int width, int height, float scale);

/* Declarations of check function */
int			ft_check(char *argv);

/* Declarations of fdf function */
t_vertices	*get_vertices_list(char	*file);

#endif