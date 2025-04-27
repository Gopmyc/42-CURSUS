/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 04:26:54 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/04/27 04:38:47 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_exit(char *str)
{
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(str, 2);
	return (0);
}

int	check_death2(t_p *p)
{
	pthread_mutex_lock(&p->a.dead);
	pthread_mutex_lock(&p->a.stop_mutex);
	if (p->a.stop)
	{
		pthread_mutex_unlock(&p->a.stop_mutex);
		pthread_mutex_unlock(&p->a.dead);
		return (1);
	}
	pthread_mutex_unlock(&p->a.stop_mutex);
	pthread_mutex_unlock(&p->a.dead);
	return (0);
}

void	stop(t_p *p)
{
	int	i;

	while (!check_death2(p))
		ft_usleep(1);
	i = 0;
	while (i < p->a.total)
		pthread_join(p->ph[i++].thread_id, NULL);
	i = 0;
	while (i < p->a.total)
		pthread_join(p->ph[i++].thread_death_id, NULL);
	pthread_mutex_destroy(&p->a.write_mutex);
	pthread_mutex_lock(&p->a.stop_mutex);
	if (p->a.stop == 2)
		printf("Each philosopher ate %d time(s)\n", p->a.m_eat);
	pthread_mutex_unlock(&p->a.stop_mutex);
	free(p->ph);
}

int	main(int argc, char **argv)
{
	t_p	p;
	int	i;

	if (!(parse_args(argc, argv, &p)))
		return (ft_exit("Invalid Arguments\n"));
	p.ph = malloc(sizeof(t_philo) * p.a.total);
	if (!p.ph)
		return (ft_exit("Malloc returned NULL\n"));
	if (!initialize(&p) || !threading(&p))
		return (free(p.ph), 0);
	i = -1;
	while (++i < p.a.total)
		if (pthread_create(&p.ph[i].thread_death_id, NULL, is_dead,
				&p.ph[i]) != 0)
			return (ft_exit("Error creating death thread\n"), free(p.ph), 0);
	stop(&p);
	return (0);
}
