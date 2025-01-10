/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:56:31 by marvin            #+#    #+#             */
/*   Updated: 2025/01/10 09:08:32 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

size_t	ft_strrec(char const *s1, char const c)
{
	size_t	i;
	size_t	rec;

	if (!(c) || !(s1))
		return (0);
	i = 0;
	rec = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			rec++;
		i++;
	}
	return (rec);
}
