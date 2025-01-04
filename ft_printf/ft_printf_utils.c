/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:53:43 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/11/07 06:09:26 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

ssize_t	ft_putnbr_fd(ssize_t n, int fd)
{
	char	c;
	ssize_t	len;

	len = 0;
	if (n == -9223372036854775807LL - 1)
	{
		write(fd, "-9223372036854775808", 20);
		return (20);
	}
	else
	{
		if (n < 0)
		{
			write(fd, "-", sizeof(char));
			len++;
			n = -n;
		}
		if (n >= 10)
			len += ft_putnbr_fd(n / 10, fd);
		c = n % 10 + '0';
		write(fd, &c, sizeof(char));
		len++;
	}
	return (len);
}

ssize_t	ft_putaddress_fd(void *ptr, int fd)
{
	size_t			i;
	size_t			start;
	unsigned long	address;
	char			*hex;
	char			buffer[18];

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	i = 0;
	address = (unsigned long)ptr;
	hex = "0123456789abcdef";
	buffer[0] = '0';
	buffer[1] = 'x';
	start = 2;
	while (i < 16 && ((address >> ((15 - i) * 4)) & 0xF) == 0)
		i++;
	while (i < 16)
	{
		buffer[start++] = hex[(address >> ((15 - i) * 4)) & 0xF];
		i++;
	}
	buffer[start] = '\0';
	return (write(fd, buffer, start));
}

ssize_t	ft_putnbr_hex_fd(unsigned long n, int fd, int uppercase)
{
	char	*hex;
	char	c;
	ssize_t	len;

	hex = "0123456789abcdef";
	len = 0;
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (n >= 16)
		len += ft_putnbr_hex_fd(n / 16, fd, uppercase);
	if (uppercase)
		hex = "0123456789ABCDEF";
	c = hex[n % 16];
	write(fd, &c, sizeof(char));
	len++;
	return (len);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	if (!(*needle))
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] && haystack[i + j] == needle[j])
			j++;
		if (j == needle_len)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
