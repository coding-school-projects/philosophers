/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:44:59 by pchennia          #+#    #+#             */
/*   Updated: 2024/06/06 14:40:09 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	uint64_t	time;

	pthread_mutex_lock(&philo->info->forks[philo->fork_l]);
	time = get_time_ms() - philo->info->start_time;
	printf("%s%7llu%s %s%3i%s %s\n", CYAN, time, X, BOLD, philo->id, \
	X, "has taken a fork");
	pthread_mutex_lock(&philo->info->forks[philo->fork_r]);
	time = get_time_ms() - philo->info->start_time;
	printf("%s%7llu%s %s%3i%s %s\n", CYAN, time, X, BOLD, philo->id, \
	X, "has taken a fork");
}

void	leave_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->info->forks[philo->fork_l]);
	pthread_mutex_unlock(&philo->info->forks[philo->fork_r]);
}

void	philo_eat(t_philo *philo)
{
	uint64_t	time;

	time = get_time_ms() - philo->info->start_time;
	printf("%s%7llu%s %s%3i%s %s\n", CYAN, time, X, BOLD, philo->id, \
	GREEN, "is eating");
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
