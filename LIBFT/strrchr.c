/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:36:05 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/10/16 03:19:27 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*last_occurrence;

	last_occurrence = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			last_occurrence = (char *)&s[i];
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (last_occurrence);
}
