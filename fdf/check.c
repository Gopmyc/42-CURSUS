/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:20:57 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/11/16 01:45:05 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_check_data(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		ft_fdf_errors("No data found.");
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

static void	ft_check_line(int fd)
{
	char	*line;
	size_t	expected_length;

	line = get_next_line(fd);
	if (!line)
		ft_fdf_errors("Unable to read input.");
	expected_length = ft_strrec(line, ' ');
	while (line)
	{
		if (expected_length != ft_strrec(line, ' '))
		{
			free(line);
			ft_fdf_errors("Inconsistent line length. Exiting.");
		}
		free(line);
		line = get_next_line(fd);
	}
}

int	ft_check(char *argv)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_fdf_errors("Error opening file.");
	ft_check_data(fd);
	if (lseek(fd, 0, SEEK_SET) == -1)
		ft_fdf_errors("Error resetting file position.");
	ft_check_line(fd);
	return (fd);
}