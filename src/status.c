/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:00:35 by jroh              #+#    #+#             */
/*   Updated: 2026/01/26 14:12:56 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	simulation_finished(t_info *info)
{
	int	finished;

	pthread_mutex_lock(&info->end_mutex);
	finished = info->simulation_end;
	pthread_mutex_unlock(&info->end_mutex);
	return (finished);
}

void	print_status(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->info->print_mutex);
	if (!simulation_finished(philo->info))
		printf("%lld %d %s\n",
			get_time() - philo->info->start_time, philo->philo_nb, msg);
	pthread_mutex_unlock(&philo->info->print_mutex);
}
