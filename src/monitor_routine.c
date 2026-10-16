/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:52:54 by haoky             #+#    #+#             */
/*   Updated: 2026/01/26 14:27:23 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_died(t_info *info, t_philo *philos, long long now, int i)
{
	pthread_mutex_lock(&info->print_mutex);
	if (!info->simulation_end)
		printf("%lld %d died\n",
			now - info->start_time, philos[i].philo_nb);
	info->simulation_end = 1;
	pthread_mutex_unlock(&info->print_mutex);
	pthread_mutex_unlock(&philos[i].meal_mutex);
}

static int	test_if_end(t_info *info, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < info->nb_philo
		&& philos[i].meals_eaten >= info->nb_time_must_eat)
		i++;
	if (i == info->nb_philo)
	{
		pthread_mutex_lock(&info->print_mutex);
		info->simulation_end = 1;
		pthread_mutex_unlock(&info->print_mutex);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_philo		*philos;
	t_info		*info;
	int			i;
	long long	now;

	philos = (t_philo *)arg;
	info = philos[0].info;
	while (1)
	{
		i = 0;
		while (i < info->nb_philo)
		{
			pthread_mutex_lock(&philos[i].meal_mutex);
			now = get_time();
			if (now - philos[i].time_last_eat > info->time_to_die)
				return (philo_died(info, philos, now, i), NULL);
			pthread_mutex_unlock(&philos[i].meal_mutex);
			i++;
		}
		if (info->nb_time_must_eat > 0)
			if (test_if_end(info, philos) == 1)
				return (NULL);
		usleep(1000);
	}
}
