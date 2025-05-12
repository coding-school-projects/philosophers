/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:45:03 by pchennia          #+#    #+#             */
/*   Updated: 2024/06/06 14:42:14 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_checker(void *arg)
{
	int			i;
	uint64_t	time;
	t_info		*info;

	info = (t_info *)arg;
	i = 0;
	while (1)
	{
		if (info->count_done == info->num_of_philos)
			break ;
		if (i == info->num_of_philos)
			i = 0;
		usleep(100);
		time = get_time_ms() - info->start_time;
		if (!info->philos[i].done
			&& ((int)(time - info->philos[i].last_ate) > info->time_to_die))
		{
			printf("%s%7llu%s %s%3i%s %s\n", CYAN, time, X, BOLD, \
				info->philos[i].id, RED, "died");
			info->is_running = false;
			break ;
		}
		i++;
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_ate = get_time_ms() - philo->info->start_time;
	if (philo->id % 2 == 1)
	{
		philo_think(philo);
		usleep(philo->info->time_to_eat * 0.25 * 1000);
	}
	while (!philo->done)
	{
		take_forks(philo);
		philo_eat(philo);
		leave_forks(philo);
		philo_think(philo);
		if (philo->ate_count == philo->info->must_eat)
		{
			philo->done = true;
			philo->info->count_done++;
			break ;
		}
		philo_sleep(philo);
	}
	return (NULL);
}
