/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:10:23 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/10 09:14:03 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	*ft_memcalloc(size_t size)
{
	void	*value;

	value = (void *)malloc(size);
	if (!value)
		return (NULL);
	ft_memset(value, 0, size);
	return (value);
}
