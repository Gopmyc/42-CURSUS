/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:26:41 by pthuilli          #+#    #+#             */
/*   Updated: 2025/01/07 08:38:02 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	void	ft_fill_str(char *str, long nb, int *i)
{
	if (nb > 9)
		ft_fill_str(str, nb / 10, i);
	str[(*i)++] = (nb % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	long	nb;
	int		i;

	nb = n;
	len = (n <= 0) * 1;
	while (n && ++len)
		n /= 10;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (nb < 0)
	{
		str[i++] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[i++] = '0';
	else
		ft_fill_str(str, nb, &i);
	str[i] = '\0';
	return (str);
}
// int main()
// {
// 	int var = 1000034; // -2147483648 2147483647 42 -42
// 	char	*str;
//
// 	str = ft_itoa(var);
// 	printf("INTLEN     : %zu\n",ft_nblen(var));
// 	printf("ITOA ASCII : %s\n", str);
// 	free(str);
// }
