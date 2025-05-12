/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:13:49 by pchennia          #+#    #+#             */
/*   Updated: 2024/06/06 14:41:32 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_threads(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_of_philos)
		pthread_detach(info->philos[i].th_id);
	free(info->philos);
}

void	destroy_mutexes(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_of_philos)
		pthread_mutex_destroy(&info->forks[i]);
	free(info->forks);
}

uint64_t	get_time_ms(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		num;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	num *= sign;
	return (num);
}
