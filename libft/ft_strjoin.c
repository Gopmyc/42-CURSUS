/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:39:56 by marvin            #+#    #+#             */
/*   Updated: 2024/10/24 10:54:44 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*array;

	i = 0;
	j = 0;
	array = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!(array))
		return (NULL);
	while (s1[i])
	{
		array[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		array[j + i] = s2[j];
		j++;
	}
	array[j + i] = '\0';
	return (array);
}
