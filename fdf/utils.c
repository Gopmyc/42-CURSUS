/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:54:40 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/04 09:29:01 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_project_3d_to_2d(t_vertex p, int *x_proj, int *y_proj)
{
	*x_proj = (*p.x) * CAMERA_DIST / (*p.z + CAMERA_DIST) + (WINDOW_WIDTH / 2);
	*y_proj = (*p.y) * CAMERA_DIST / (*p.z + CAMERA_DIST) + (WINDOW_HEIGHT / 2);
}

void ft_project_3d_to_2d_isometric(t_vertex p, int *x_proj, int *y_proj, float scale)
{
    *x_proj = (int)(((*p.x - *p.y) * cos(M_PI / 6) + (WINDOW_WIDTH / 2)) * scale);
    *y_proj = (int)(((*p.x + *p.y) * sin(M_PI / 6) - *p.z * CAMERA_DIST / (*p.z + CAMERA_DIST) + (WINDOW_HEIGHT / 2)) * scale);
}

void	ft_fdf_errors(char *s)
{
	char	*error;
	size_t	error_len;

	error_len = ft_strlen("[FDF] : ") + ft_strlen(s) + 1;
	error = (char *)ft_memcalloc(error_len);
	if (!(error))
	{
		ft_printf("Memory allocation failed for error message\n");
		exit(-1);
	}
	ft_strlcpy(error, "[FDF] : ", error_len);
	ft_strlcat(error, s, error_len);
	ft_printf("%s\n", error);
	ft_printf("An error occurred. Please check your inputs.\n");
	free(error);
	exit(-1);
}

int	*get_next_number(char **str, char separator)
{
	static int	number;
	int			sign;

	number = 0;
	sign = 1;
	while (**str && (**str == ' ' || **str == '\t'))
		(*str)++;
	if (**str == '\0' || **str == '\n' || **str == '\r')
		return (NULL);
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	while (**str && **str != separator && **str != ' ' && **str != '\t' && **str != '\n' && **str != '\r')
	{
		if (!(ft_isdigit(**str)))
			ft_fdf_errors("The character string is not in the correct format");
		number = number * 10 + (**str - '0');
		(*str)++;
	}
	while (**str && (**str == ' ' || **str == '\t' || **str == separator))
		(*str)++;
	number *= sign;
	return (&number);
}

void	ft_calculate_bounds(t_vertices *vertices, int *min_x, int *max_x, int *min_y, int *max_y)
{
	t_vertices	*current;
	int			x;
	int			y;

	*min_x = INT_MAX;
	*max_x = INT_MIN;
	*min_y = INT_MAX;
	*max_y = INT_MIN;

	current = vertices;
	while (current)
	{
		ft_project_3d_to_2d(*(current->point), &x, &y);
		if (x < *min_x)
			*min_x = x;
		if (x > *max_x)
			*max_x = x;
		if (y < *min_y)
			*min_y = y;
		if (y > *max_y)
			*max_y = y;
		current = current->next_point;
	}
}
