/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:11:51 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/10/30 22:40:23 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*get_next_line(int fd)
{
	char			*line;
	ssize_t			bytes;

	line = ft_allocate_line((BUFFER + 1) * sizeof(char));
	if (!line)
		return (NULL);
	bytes = ft_read_line(fd, line);
	if ((bytes < 0) || ((bytes == 0) && (increment() >= 2)))
	{
		free(line);
		return (NULL);
	}
	return (line);
}
