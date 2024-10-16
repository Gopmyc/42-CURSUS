/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:36:05 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/10/16 04:09:46 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (SIZE_MAX / nmemb < size)
		return (NULL);
	array = malloc(nmemb * size);
	if (!array)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		((unsigned char *)array)[i] = 0;
		i++;
	}
	return (array);
}
