/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:12:56 by pthuilli          #+#    #+#             */
/*   Updated: 2025/01/07 08:38:02 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	if (!*to_find)
		return ((char *)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] == str[i] && str[i] != '\0' && i < len)
		{
			i++;
			j++;
		}
		if ((!to_find[j]) != '\0')
			return ((char *)str + (i - j));
		i = (i - j) + 1;
	}
	return (NULL);
}

// int main()
// {
// 	printf("Resulat : %s\n",ft_strnstr("abcdesss","bc",4));
// }
