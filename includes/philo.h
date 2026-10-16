/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haoky <haoky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:41:24 by haoky             #+#    #+#             */
/*   Updated: 2026/01/26 14:25:25 by haoky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef pthread_mutex_t	t_mutex;

typedef struct s_info
{
	int			nb_philo;
	long long	time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nb_time_must_eat;
	long long	start_time;

	t_mutex		*forks;
	t_mutex		start_mutex;
	t_mutex		print_mutex;
	t_mutex		end_mutex;

	int			simulation_end;
}				t_info;

typedef struct s_philo
{
	int			philo_nb;
	int			meals_eaten;
	long long	time_last_eat;

	t_mutex		meal_mutex;
	t_mutex		*left_fork;
	t_mutex		*right_fork;

	t_info		*info;
	pthread_t	thread;
}				t_philo;

int				ft_atoi(const char *str);
long long		get_time(void);
long long		timediff_ms(t_philo *philos);
void			print_error(char *msg);
void			init_info(int arc, char **arv, t_info *info);
void			init_philos(t_philo *philos, t_info *info);
int				init_forks(t_info *info);
void			init_eating(t_philo *philos);
int				someone_died(t_philo *philos);
void			print_status(t_philo *philo, char *msg);
void			start_simulation(t_philo *philos);
void			*routine(void *arg);
void			*monitor_routine(void *arg);
void			destroy_all(t_info *info, t_philo *philos);
int				simulation_finished(t_info *info);

#endif
