/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 04:26:47 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/04/27 04:30:17 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*is_dead(void *data)
{
	t_philo	*ph;

	ph = (t_philo *)data;
	while (!check_death(ph, 0))
	{
		pthread_mutex_lock(&ph->pa->time_eat);
		pthread_mutex_lock(&ph->pa->finish);
		if (!ph->finish && ((actual_time()
					- ph->ms_eat) >= (long)(ph->pa->die)))
		{
			pthread_mutex_unlock(&ph->pa->finish);
			pthread_mutex_unlock(&ph->pa->time_eat);
			pthread_mutex_lock(&ph->pa->write_mutex);
			write_status("died\n", ph);
			pthread_mutex_unlock(&ph->pa->write_mutex);
			check_death(ph, 1);
			break ;
		}
		pthread_mutex_unlock(&ph->pa->time_eat);
		pthread_mutex_unlock(&ph->pa->finish);
		usleep(100);
	}
	return (NULL);
}

void	*thread(void *data)
{
	t_philo	*ph;

	ph = (t_philo *)data;
	if (ph->id % 2 == 0)
		ft_usleep(ph->pa->eat / 10);
	while (!check_death(ph, 0))
	{
		activity(ph);
		if ((int)++ph->nb_eat == ph->pa->m_eat)
		{
			pthread_mutex_lock(&ph->pa->finish);
			ph->finish = 1;
			ph->pa->nb_p_finish++;
			if (ph->pa->nb_p_finish == ph->pa->total)
			{
				pthread_mutex_unlock(&ph->pa->finish);
				check_death(ph, 2);
			}
			else
				pthread_mutex_unlock(&ph->pa->finish);
			return (NULL);
		}
	}
	return (NULL);
}

int	threading(t_p *p)
{
	int	i;

	i = 0;
	while (i < p->a.total)
	{
		p->ph[i].pa = &p->a;
		if (pthread_create(&p->ph[i].thread_id, NULL, thread, &p->ph[i]) != 0)
			return (ft_exit("Error creating main thread\n"));
		i++;
	}
	return (1);
}
