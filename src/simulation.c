/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:29:07 by haoky             #+#    #+#             */
/*   Updated: 2026/01/19 13:32:01 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_simulation(t_philo *philos)
{
	int		i;
	t_info	*info;

	info = philos[0].info;
	i = 0;
	pthread_mutex_lock(&info->start_mutex);
	while (i < info->nb_philo)
	{
		pthread_create(&philos[i].thread, NULL, routine, &philos[i]);
		i++;
	}
	info->start_time = get_time();
	printf ("0 Simulation starts\n");
	i = 0;
	while (i < info->nb_philo)
	{
		philos[i].time_last_eat = info->start_time;
		i++;
	}
	pthread_mutex_unlock(&info->start_mutex);
}
