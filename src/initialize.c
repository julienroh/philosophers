/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:02:23 by jroh              #+#    #+#             */
/*   Updated: 2026/01/26 14:25:57 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_info *info)
{
	int	i;

	i = 0;
	info->forks = malloc(sizeof(t_mutex) * info->nb_philo);
	if (!info->forks)
		return (1);
	while (i < info->nb_philo)
	{
		if (pthread_mutex_init(&info->forks[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

void	init_info(int argc, char **argv, t_info *info)
{
	if (argc != 5 && argc != 6)
	{
		print_error("Error : need 4 or 5 arguments\n");
		exit (1);
	}
	info->nb_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->simulation_end = 0;
	if (argc == 6)
		info->nb_time_must_eat = ft_atoi(argv[5]);
	if (info->nb_philo <= 0
		|| info->time_to_die <= 0
		|| info->time_to_eat <= 0
		|| info->time_to_sleep <= 0
		|| (argc == 6 && info->nb_time_must_eat <= 0))
	{
		printf("Error : invalid arguments\n");
		exit(1);
	}
	info->forks = NULL;
	info->simulation_end = 0;
	info->start_time = 0;
}

void	init_philos(t_philo *philos, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		philos[i].philo_nb = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].info = info;
		philos[i].left_fork = &info->forks[i];
		if (i + 1 == info->nb_philo)
			philos[i].right_fork = &info->forks[0];
		else
			philos[i].right_fork = &info->forks[i + 1];
		i++;
	}
}
