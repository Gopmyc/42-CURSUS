/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:27:02 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/10/30 22:55:32 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_allocate_line(size_t size)
{
	char	*line;

	line = (char *)malloc(((size_t)size + 1) * sizeof(char));
	return (line);
}

int	increment(void)
{
	static int		value;

	value++;
	return (value);
}

size_t	ft_strlen(char	*str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static char	*ft_extend_size(char *line)
{
	size_t	i;
	char	*new_line;
	size_t	len;

	i = 0;
	len = ft_strlen(line);
	if (!(line))
		return (NULL);
	new_line = ft_allocate_line((len * 2) + 1);
	if (!(new_line))
		return (NULL);
	while (line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	free(line);
	return (new_line);
}

int	ft_read_line(int fd, char *line)
{
	size_t			i;
	ssize_t			bytes;
	char			element;

	i = 0;
	bytes = read(fd, &element, 1);
	while (bytes > 0)
	{
		if (line && (i >= (BUFFER - 1)))
		{
			line[i++] = '\0';
			line = ft_extend_size(line);
			if (!line)
				return (-1);
		}
		line[i++] = element;
		if (element == '\n')
			break ;
		bytes = read(fd, &element, 1);
	}
	line[i] = '\0';
	return (bytes);
}
