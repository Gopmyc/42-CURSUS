/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 04:48:54 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/11/14 22:11:35 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	handle_char(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	return (write(1, &c, 1));
}

int	handle_string(va_list args)
{
	char	*s;

	s = va_arg(args, char *);
	if (s)
		return (write(1, s, ft_strlen(s)));
	return (write(1, "(null)", 6));
}

int	handle_pointer(va_list args)
{
	void	*p;

	p = va_arg(args, void *);
	return (ft_putaddress_fd(p, 1));
}

int	handle_int(va_list args, int is_unsigned)
{
	ssize_t			i;
	unsigned int	temp;
	char			buffer[10];
	int				len;

	len = 0;
	if (is_unsigned)
	{
		temp = (unsigned int)va_arg(args, unsigned int);
		if (temp == 0)
			return (write(1, "0", sizeof(char)));
		while (temp > 0)
		{
			buffer[len++] = (temp % 10) + '0';
			temp /= 10;
		}
		i = len - 1;
		while (i >= 0)
			write(1, &buffer[i--], 1);
	}
	else
		len = ft_putnbrlong_fd((ssize_t)va_arg(args, int), 1);
	return (len);
}

int	handle_hex(va_list args, char specifier)
{
	size_t	hex;

	hex = (size_t)va_arg(args, unsigned int);
	return (ft_putnbr_hex_fd(hex, 1, (specifier == 'X')));
}
