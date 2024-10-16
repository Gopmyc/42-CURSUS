/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:02:27 by ghoyaux           #+#    #+#             */
/*   Updated: 2024/10/16 02:32:40 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int ch)
{
	if ((ch >= 48 && ch <= 57)
		|| (ch >= 65 && ch <= 90)
		|| (ch >= 97 && ch <= 122))
		return (1);
	return (0);
}