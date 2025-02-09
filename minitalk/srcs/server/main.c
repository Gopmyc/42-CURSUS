/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:18:41 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/09 11:53:40 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shared.h"
#include "../../includes/server.h"

static void	handle_signal(int iSignal, siginfo_t *pInfo, void *pContext)
{
	static char	cChar;
	static int	iBit;

	(void)pContext;
	(void)pInfo;
	cChar = (cChar << 1) | (iSignal == SIGUSR2);
	iBit++;
	if (iBit == 8)
	{
		if (cChar == '\0')
			write(1, "\n", 1);
		else
			write(1, &cChar, 1);
		iBit = 0;
		cChar = 0;
	}
}

int	main(int iAc, char **ppAv)
{
	struct sigaction	sSa;

	(void)ppAv;
	if (iAc > 1)
		return (ft_error("Error: The 'server' program does not accept arguments"));
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);

	sSa.sa_sigaction = handle_signal;
	sSa.sa_flags = SA_SIGINFO;
	sigemptyset(&sSa.sa_mask);

	sigaction(SIGUSR1, &sSa, NULL);
	sigaction(SIGUSR2, &sSa, NULL);

	while (1)
		pause();
	return (0);
}
