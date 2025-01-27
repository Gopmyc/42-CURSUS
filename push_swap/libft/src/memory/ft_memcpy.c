/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:36:05 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/27 09:07:59 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Fonction false but idk for why*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if ((dest == src) || n == 0)
		return (dest);
	while (n--)
		((char *)dest)[n] = ((const char *)src)[n];
	return (dest);
}
