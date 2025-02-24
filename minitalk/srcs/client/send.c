/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:14:16 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/10 03:06:10 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shared.h"
#include "../../includes/client.h"

static int	send_char(pid_t iPid, char cChar)
{
	int	i_bit;

	i_bit = 8;
	while (i_bit--)
	{
		if ((cChar >> i_bit) & 1)
		{
			if (kill(iPid, SIGUSR2) == -1)
				return (-1);
		}
		else
		{
			if (kill(iPid, SIGUSR1) == -1)
				return (-1);
		}
		usleep(100);
	}
	return (0);
}

int	send_message(pid_t iPid, char *sMessage)
{
	while (*sMessage)
		if (send_char(iPid, *sMessage++) == -1)
			return (-1);
	if (send_char(iPid, '\0') == -1)
		return (-1);
	return (0);
}
