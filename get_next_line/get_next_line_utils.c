/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:11:51 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/11/16 01:29:07 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_strndup(char *str, int start, int size)
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
