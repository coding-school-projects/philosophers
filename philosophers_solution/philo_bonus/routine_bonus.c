/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:25:37 by pchennia          #+#    #+#             */
/*   Updated: 2024/06/06 14:42:38 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	process(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_of_philos)
	{
		info->philos[i].pid = fork();
		if (info->philos[i].pid < 0)
		{
			printf("Error! Fork");
			exit(-1);
		}
		if (info->philos[i].pid == 0)
			routine(&info->philos[i]);
	}
	pthread_create(&info->is_running, NULL, wait_process, info);
	pthread_detach(info->is_running);
}

void	routine(t_philo *philo)
{
	pthread_t	checklife;

	if (philo->id % 2 == 1)
	{
		philo_think(philo);
		usleep(philo->info->time_to_eat * 0.25 * 1000);
	}
	philo->last_ate = 0;
	pthread_create(&checklife, NULL, routine_checker, philo);
	pthread_detach(checklife);
	while (1)
	{
		take_forks(philo);
		philo_eat(philo);
		leave_forks(philo);
		philo_think(philo);
		if (philo->ate_count == philo->info->must_eat)
			exit(1);
		philo_sleep(philo);
	}
	exit(1);
}

void	*routine_checker(void *arg)
{
	t_philo		*philo;
	uint64_t	time;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->ate_count == philo->info->must_eat)
			break ;
		time = get_time_ms() - philo->info->start_time;
		if (((int)(time - philo->last_ate)) > philo->info->time_to_die)
		{
			sem_wait(philo->info->typing);
			printf("%s%7llu%s %s%3i%s %s\n", CYAN, time, X, BOLD, philo->id, \
			X, "died");
			sem_post(philo->info->is_died);
			break ;
		}
		usleep(100);
	}
	return (NULL);
}

void	*wait_process(void *arg)
{
	int		i;
	t_info	*info;

	info = (t_info *)arg;
	i = -1;
	while (++i < info->num_of_philos)
		waitpid(-1, NULL, 0);
	sem_post(info->is_died);
	return (NULL);
}
