/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:53:34 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/11/11 17:42:37 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/*
	--> %c Prints a single character.
		--> write
	--> %s Prints a string (as defined by the common C convention).
		--> ft_putstr_fd
	--> %p The void * pointer argument has to be printed in hexadecimal format.
		--> ft_putaddress_fd
	--> %d Prints a decimal (base 10) number.
		--> ft_putnbr_fd
	--> %i Prints an integer in base 10.
		--> ft_putnbr_fd
	-->	%u Prints an unsigned decimal (base 10) number.
		--> ft_putunbr_fd
	-->	%x Prints a number in hexadecimal (base 16) lowercase format.
		--> ft_putnbr_hex_fd
	-->	%X Prints a number in hexadecimal (base 16) uppercase format.
		--> ft_putnbr_hex_fd
	-->	%% Prints a percent sign.
		--> ft_printf gere le cas
*/

/* Function declaration of ft_printf_utils.c : */
size_t					ft_strlen(const char *str);
ssize_t					ft_putnbr_fd(ssize_t n, int fd);
ssize_t					ft_putaddress_fd(void *ptr, int fd);
ssize_t					ft_putnbr_hex_fd(unsigned long n, int fd,
							int uppercase);
char					*ft_strstr(const char *haystack, const char *needle);

/* Function declaration of ft_printf_handle.c : */
int						handle_char(va_list args);
int						handle_string(va_list args);
int						handle_pointer(va_list args);
int						handle_int(va_list args, int is_unisgned);
int						handle_hex(va_list args, char specifier);

/* Function declaration of dt_printf_utils.c : */
int						ft_printf(const char *str, ...);