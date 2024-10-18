/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:56:31 by marvin            #+#    #+#             */
/*   Updated: 2024/10/16 19:56:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strrec(char const *s1, char const c)
{
	size_t	i;
	size_t	rec;

	if (!(c) || !(s1))
		return (NULL);
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
