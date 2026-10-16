/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 11:47:05 by haoky             #+#    #+#             */
/*   Updated: 2026/01/19 15:02:40 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info		info;
	t_philo		*philos;
	pthread_t	monitor;
	int			i;

	init_info(argc, argv, &info);
	if (pthread_mutex_init(&info.start_mutex, NULL)
		|| pthread_mutex_init(&info.print_mutex, NULL)
		|| pthread_mutex_init(&info.end_mutex, NULL))
		return (1);
	philos = malloc(sizeof(t_philo) * info.nb_philo);
	if (!philos)
		return (1);
	if (init_forks(&info))
		return (1);
	init_philos(philos, &info);
	start_simulation(philos);
	if (pthread_create(&monitor, NULL, monitor_routine, philos))
		return (1);
	i = 0;
	while (i < info.nb_philo)
		pthread_join(philos[i++].thread, NULL);
	pthread_join(monitor, NULL);
	destroy_all(&info, philos);
	return (0);
}
