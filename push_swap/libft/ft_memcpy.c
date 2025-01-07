/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:11:40 by pthuilli          #+#    #+#             */
/*   Updated: 2025/01/07 08:38:02 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	if (!dst && !src)
		return (NULL);
	tmp1 = (unsigned char *)src;
	tmp2 = (unsigned char *)dst;
	while (n > 0)
	{
		*tmp2++ = *tmp1++;
		n--;
	}
	return (dst);
}
