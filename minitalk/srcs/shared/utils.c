/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:22:57 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/10 03:40:40 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shared.h"

int	ft_error(char *sMsg)
{
	if (!sMsg)
		write(STDERR_FILENO, "Error\n", 6);
	else
	{
		while (*sMsg)
			write(STDERR_FILENO, sMsg++, 1);
		write(STDERR_FILENO, "\n", 1);
	}
	exit(-1);
	return (-1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		write(fd, "-2147483648", (11 * sizeof(char)));
	else
	{
		if (n < 0)
		{
			write(fd, "-", sizeof(char));
			n = -n;
		}
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		c = n % 10 + '0';
		write(fd, &c, sizeof(char));
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], sizeof(char));
		i++;
	}
}

long	ft_atol(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result * sign > INT_MAX)
			return ((long)INT_MAX + 1);
		if (result * sign < INT_MIN)
			return ((long)INT_MIN - 1);
		str++;
	}
	return (result * sign);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
