/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 08:29:33 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/05 08:46:52 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int		i;
	int		neg;
	long	value;

	i = 0;
	value = 0;
	neg = 0;
	while ((nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] == '-')
		neg = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] != '\0' && (nptr[i] >= 48 && nptr[i] <= 57))
	{
		if (value > 922337203685477580 || (value == 922337203685477580
				&& ((!neg && nptr[i] - '0' > 7) || (neg && nptr[i] - '0' > 8))))
			return (-1 * !neg);
		else
			value = (value * 10) + nptr[i++] - '0';
	}
	if (neg)
		value = -value;
	return (value);
}
