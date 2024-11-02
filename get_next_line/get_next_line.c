/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:11:51 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/11/02 00:55:18 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			element;
	char			*line;
	ssize_t			bytes;
	size_t			i;

	line = (char *)malloc((BUFFER + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	bytes = read(fd, &element, 1);
	while (bytes > 0)
	{
		if (line && (i >= (BUFFER - 2)))
			line = extend_size(line, BUFFER);
		line[i++] = element;
		if (element == '\n')
			break ;
		bytes = read(fd, &element, 1);
	}
	line[i++] = '\0';
	return (procedure_useless(bytes, line));
}
