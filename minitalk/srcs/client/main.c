/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:18:37 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/10 03:45:55 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shared.h"
#include "../../includes/client.h"

int	main(int i_ac, char **p_av)
{
	pid_t	i_pid;

	if (i_ac != 3)
		return (ft_error(
				"Error: The number of arguments is not correct, "
				"try: ./client <PID> <MESSAGE>"
			));
	i_pid = (pid_t)ft_atol(p_av[1]);
	if (i_pid <= 0 || i_pid > 4194304)
		return (ft_error(
				"Error: Invalid PID. "
				"The first argument must be a "
				"valid positive PID within system limits."
			));
	if (ft_strlen(p_av[2]) > 1200)
		return (ft_error(
				"Error: Message too long. "
				"Messages must not be greater than 1200 bytes."
			));
	if (send_message(i_pid, p_av[2]) == -1)
		return (ft_error(
				"Error: Failed to send message. "
				"Ensure the server is running and the PID is correct."
			));
	return (EXIT_SUCCESS);
}
