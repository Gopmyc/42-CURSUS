/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:39:56 by marvin            #+#    #+#             */
/*   Updated: 2024/10/16 19:39:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	size_s1;
	size_t	size_s2;
	char	*array;

	i = 0;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2); 
	array = (char *)malloc((size_s1 + size_s2) + 1);
	if (!(array))
		return (NULL);
	while (s1[i])
	{
		array[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		array[size_s1 + i] = s2[i];
		i++;
	}
	array[(size_s1 + size_s2) + 1] = '\0';
	return (array);
}
