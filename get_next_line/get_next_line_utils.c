/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:27:02 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/10/29 22:40:22 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_allocate_line(size_t size)
{
	char	*line;

	line = (char *)malloc(((size_t)size + 1) * sizeof(char));
	return (line);
}

static char	*ft_extend_size(char *line)
{
	size_t	i;
	char	*new_line;

	i = 0;
	while (line[i])
		i++;
	new_line = ft_allocate_line((BUFFER_SIZE + i));
	if (!(new_line))
		return (NULL);
	i = 0;
	while (line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	free(line);
	return (new_line);
}

int	ft_read_line(int fd, char *line, )
{
	size_t			i;
	ssize_t			bytes;
	char			element;

	i = 0;
	bytes = read(fd, &element, 1);
	while (bytes > 0)
	{
		if (i >= BUFFER_SIZE)
		{
			line[i + 1] = '\0';
			line = ft_extend_size(line);
			if (!(line))
				return (-1);
		}
		line[i] = element;
		if (element == '\n')
			break ;
		bytes = read(fd, &element, 1);
		i++;
	}
	line[i] = '\0';
	return (bytes);
}
