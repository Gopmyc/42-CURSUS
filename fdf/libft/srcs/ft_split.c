/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 08:29:52 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/19 09:56:10 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	*ft_push(const char *s, int begin, int end, t_mem_manager *manager)
{
	int		i;
	char	*temp;

	i = 0;
	temp = mem_alloc(manager, sizeof(*temp) * (end - begin + 1));
	if (!temp)
		return (NULL);
	while (begin < end)
	{
		temp[i] = s[begin];
		i++;
		begin++;
	}
	temp[i] = '\0';
	return (temp);
}

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(const char *s, char c, t_mem_manager *manager)
{
	char	**ret;
	int		begin;
	int		word;
	int		i;

	if (!s)
		return (NULL);
	ret = mem_alloc(manager, sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!ret)
		return (NULL);
	i = -1;
	word = -1;
	while (s[++i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			begin = i;
		if ((i != 0 && s[i] == c && s[i - 1] != c)
			|| (s[i + 1] == '\0' && s[i] != c))
			ret[++word] = ft_push(s, begin, i + (s[i] != c), manager);
		if (word != -1 && !ret[word])
			return (NULL);
	}
	ret[++word] = NULL;
	return (ret);
}
