/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:18:41 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/02/10 03:35:24 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shared.h"
#include "../../includes/server.h"

static void	handle_signal(int i_signal, siginfo_t *p_info, void *p_context)
{
	static char		c_char;
	static int		i_bit;
	static pid_t	last_pid;

	(void)p_context;
	if (last_pid != 0 && last_pid != p_info->si_pid && i_bit > 0)
	{
		c_char = 0;
		i_bit = 0;
	}
	last_pid = p_info->si_pid;
	c_char = c_char << 1;
	c_char |= (i_signal == SIGUSR2);
	i_bit++;
	if (i_bit == 8)
	{
		if (c_char == '\0')
			write(1, "\n", 1);
		else
			write(1, &c_char, 1);
		i_bit = 0;
		c_char = 0;
	}
}

int	main(int iAc, char **ppAv)
{
	struct sigaction	s_sa;

	(void)ppAv;
	if (iAc > 1)
		return (ft_error(
				"Error: The 'server' "
				"program does not accept arguments"
			));
	s_sa.sa_sigaction = handle_signal;
	s_sa.sa_flags = SA_SIGINFO;
	sigemptyset(&s_sa.sa_mask);
	sigaction(SIGUSR1, &s_sa, NULL);
	sigaction(SIGUSR2, &s_sa, NULL);
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
