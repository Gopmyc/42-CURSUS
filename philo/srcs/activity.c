/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 04:26:33 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/04/27 04:38:10 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	write_status(char *str, t_philo *ph)
{
	long int	time;

	time = -1;
	time = actual_time() - ph->pa->start_t;
	if (time >= 0 && time <= 2147483647 && !check_death(ph, 0))
	{
		printf("%ld ", time);
		printf("Philo %d %s", ph->id, str);
	}
}

void	sleep_think(t_philo *ph)
{
	pthread_mutex_lock(&ph->pa->write_mutex);
	write_status("is sleeping\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	ft_usleep(ph->pa->sleep);
	pthread_mutex_lock(&ph->pa->write_mutex);
	write_status("is thinking\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
}

static void	take_forks_and_eat(t_philo *ph,
	pthread_mutex_t *first, pthread_mutex_t *second)
{
	pthread_mutex_lock(second);
	pthread_mutex_lock(&ph->pa->write_mutex);
	write_status("has taken a fork\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	pthread_mutex_lock(&ph->pa->write_mutex);
	write_status("is eating\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	pthread_mutex_lock(&ph->pa->time_eat);
	ph->ms_eat = actual_time();
	pthread_mutex_unlock(&ph->pa->time_eat);
	ft_usleep(ph->pa->eat);
	pthread_mutex_unlock(second);
	pthread_mutex_unlock(first);
	sleep_think(ph);
}

void	activity(t_philo *ph)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	if (&ph->l_f < ph->r_f)
	{
		first = &ph->l_f;
		second = ph->r_f;
	}
	else
	{
		first = ph->r_f;
		second = &ph->l_f;
	}
	pthread_mutex_lock(first);
	pthread_mutex_lock(&ph->pa->write_mutex);
	write_status("has taken a fork\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	if (!ph->r_f)
	{
		ft_usleep(ph->pa->die * 2);
		pthread_mutex_unlock(first);
		return ;
	}
	take_forks_and_eat(ph, first, second);
}
