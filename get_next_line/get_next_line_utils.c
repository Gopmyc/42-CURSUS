/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:11:51 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/11/03 05:55:35 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

char	*ft_strndup(char *str, int start, int size)
{
	char	*dst;
	int		i;

	if (!str || start < 0 || size < 0)
		return (NULL);
	dst = (char *)malloc((size + 1) * sizeof(char));
	if (!(dst))
		return (NULL);
	i = 0;
	while (i < size && str[start + i] != '\0')
	{
		dst[i] = str[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		len;

	if (!buffer || !buffer[0])
		return (NULL);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	line = ft_strndup(buffer, 0, len + (buffer[len] == '\n'));
	return (line);
}

char	*ft_next_line(char *buffer)
{
	size_t	i;
	char	*str;

	i = 0;
	str = NULL;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i++])
	{
		str = ft_strndup(buffer, i, (ft_strlen(buffer) - i + 1));
		if (!(str))
			return (NULL);
	}
	free(buffer);
	return (str);
}
