/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:39:01 by marvin            #+#    #+#             */
/*   Updated: 2024/10/16 19:39:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t  i;
	char    *array;

    i = 0;
    array = (char *)malloc(len + 1);
    if (!(array))
        return (NULL);
    while (i < len)
    {
        array[i] = s[start + i];
        i++;
    }
    array[i] = '\0';
    return (array);
}
