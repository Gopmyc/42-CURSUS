/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:18:37 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/09 11:37:53 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shared.h"
#include "../../includes/client.h"

int main(int iAc, char **ppAv)
{
	pid_t iPid;

	if (iAc != 3)
		return (ft_error("Error: The 'client' program only accepts two arguments: the 'PID' of the server and the message to transmit."));
	iPid = (pid_t)ft_atol(ppAv[1]);
	if (iPid <= 0 || iPid > 4194304)
		return (ft_error("Error: Invalid PID. The first argument must be a valid positive PID within system limits."));
	if (send_message(iPid, ppAv[2]) == -1)
		return (ft_error("Error: Failed to send message. Ensure the server is running and the PID is correct."));
	return (EXIT_SUCCESS);
}
