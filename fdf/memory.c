/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 22:18:57 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/11/16 00:34:08 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_memcalloc(size_t size)
{
	void	*content;

	content = (void *)malloc(size);
	if (!content)
		return (NULL);
	ft_memset(content, 0, size);
	return (content);
}
