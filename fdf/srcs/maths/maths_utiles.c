/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 08:12:10 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/06 08:14:57 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

float	ft_abs(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_ipart(float n)
{
	return ((int)n);
}

float	ft_fpart(float n)
{
	if (n > 0.f)
		return (n - ft_ipart(n));
	return (n - (ft_ipart(n) + 1.f));
}

float	ft_rfpart(float n)
{
	return (1.f - ft_fpart(n));
}
