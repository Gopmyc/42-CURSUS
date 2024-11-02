/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:27:02 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/11/02 00:07:04 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char	*str)
{
	size_t	len;

	len = 0;
	if (!(str))
		return (0);
	while (str[len])
		len++;
	return (len);
}

int	increment(size_t reset)
{
	static int		value;

	if (reset)
		value = 0;
	else
		value++;
	return (value);
}

static char	*ft_strdup(char *s)
{
	size_t	i;
	char	*array;

	i = 0;
	array = (char *)malloc(ft_strlen(s) + 1);
	if (!array)
		return (NULL);
	while (s[i])
	{
		array[i] = s[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

char	*extend_size(char *cpy, size_t size)
{
	size_t	i;
	char	*dst;
	char	*cpy_tmp;

	i = 0;
	cpy_tmp = ft_strdup(cpy);
	if (!(cpy_tmp))
		return (NULL);
	if (cpy)
		free(cpy);
	dst = (char *)malloc((ft_strlen(cpy_tmp) + 1) + size);
	if (!dst)
		return (NULL);
	while (cpy_tmp[i])
	{
		dst[i] = cpy_tmp[i];
		i++;
	}
	if (cpy_tmp)
		free(cpy_tmp);
	dst[i] = '\0';
	return (dst);
}

char	*procedure_useless(ssize_t bytes, char *line)
{
	if ((bytes < 0) || ((bytes == 0) && (increment(0) >= 2)))
	{
		if (line)
			free(line);
		increment(1);
		return (NULL);
	}
	return (line);
}
