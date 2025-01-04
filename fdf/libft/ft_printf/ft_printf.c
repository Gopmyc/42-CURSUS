/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:53:38 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/11/13 11:11:40 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	handle_format(va_list args, char format)
{
	if (format == 'c')
		return (handle_char(args));
	else if (format == 's')
		return (handle_string(args));
	else if (format == 'p')
		return (handle_pointer(args));
	else if (format == 'd' || format == 'i' || format == 'u')
		return (handle_int(args, (format == 'u')));
	else if (format == 'x' || format == 'X')
		return (handle_hex(args, format));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			written;
	const char	*format;

	va_start(args, str);
	written = 0;
	format = str;
	while (format && *format)
	{
		if (*format == '%' && *(format + 1) == '%')
		{
			written += write(1, "%", 1);
			format += 2;
		}
		else if (*format == '%' && *(format + 1))
		{
			written += handle_format(args, *(++format));
			format++;
		}
		else
			written += write(1, format++, 1);
	}
	va_end(args);
	return (written);
}
