/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:36:05 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/27 09:07:59 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

static void	free_all(char **array, size_t j)
{
	while (j > 0)
		free(array[--j]);
	free(array);
}

static char	*allocate_word(const char *s, size_t start, size_t end)
{
	char	*word;
	size_t	i;

	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static size_t	fill_array(const char *s, char c, char **array)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			array[j] = allocate_word(s, start, i);
			if (!array[j])
			{
				free_all(array, j);
				return (0);
			}
			j++;
		}
	}
	return (j);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	size_t	word_count;
	size_t	words_filled;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	array = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	words_filled = fill_array(s, c, array);
	if (!words_filled && word_count > 0)
		return (NULL);
	array[word_count] = NULL;
	return (array);
}
