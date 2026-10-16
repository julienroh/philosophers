/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:03:30 by haoky             #+#    #+#             */
/*   Updated: 2026/01/19 15:06:06 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_all(t_info *info, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
		pthread_mutex_destroy(&info->forks[i++]);
	pthread_mutex_destroy(&info->start_mutex);
	pthread_mutex_destroy(&info->print_mutex);
	pthread_mutex_destroy(&info->end_mutex);
	i = 0;
	while (i < info->nb_philo)
		pthread_mutex_destroy(&philos[i++].meal_mutex);
	free(info->forks);
	free(philos);
}
