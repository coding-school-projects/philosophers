/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:24:32 by pchennia          #+#    #+#             */
/*   Updated: 2024/06/06 14:42:24 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_forks(t_philo *philo)
{
	uint64_t	time;

	sem_wait(philo->info->forks);
	time = get_time_ms() - philo->info->start_time;
	printf("%s%7llu%s %s%3i%s %s\n", CYAN, time, X, BOLD, philo->id, \
	X, "has taken a fork");
	sem_wait(philo->info->forks);
	time = get_time_ms() - philo->info->start_time;
	printf("%s%7llu%s %s%3i%s %s\n", CYAN, time, X, BOLD, philo->id, \
	X, "has taken a fork");
}

void	leave_forks(t_philo *philo)
{
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
}

void	philo_eat(t_philo *philo)
{
	uint64_t	time;

	time = get_time_ms() - philo->info->start_time;
	printf("%s%7llu%s %s%3i%s %s\n", CYAN, time, X, BOLD, philo->id, \
	X, "is eating");
	philo->last_ate = time;
	philo->ate_count++;
	usleep(philo->info->time_to_eat * 1000);
}

void	philo_sleep(t_philo *philo)
{
	uint64_t	time;

	time = get_time_ms() - philo->info->start_time;
	printf("%s%7llu%s %s%3i%s %s\n", CYAN, time, X, BOLD, philo->id, \
	X, "is sleeping");
	usleep(philo->info->time_to_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	uint64_t	time;

	time = get_time_ms() - philo->info->start_time;
	printf("%s%7llu%s %s%3i%s %s\n", CYAN, time, X, BOLD, philo->id, \
	X, "is thinking");
}
