/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:12:46 by pchennia          #+#    #+#             */
/*   Updated: 2024/06/06 14:42:30 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init(int argc, char *argv[], t_info *info)
{
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > 200)
	{
		printf("Number of philosopher should be 0 to 200\n");
		exit(-1);
	}
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
	{
		printf("Invalid time or Time cannot be smaller than 60ms\n");
		exit(-1);
	}
	info->num_of_philos = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->must_eat = -1;
	if (argc == 6 && ft_atoi(argv[5]) <= 0)
	{
		printf("Invalid number of times each philosopher must eat\n");
		exit(-1);
	}
	if (argc == 6)
		info->must_eat = ft_atoi(argv[5]);
	info->start_time = get_time_ms();
}

void	init_philo(t_info *info)
{
	int	i;

	info->philos = malloc(sizeof(t_philo) * info->num_of_philos);
	i = -1;
	while (++i < info->num_of_philos)
	{
		info->philos[i].id = i + 1;
		info->philos[i].ate_count = 0;
		info->philos[i].last_ate = 0;
		info->philos[i].info = info;
	}
}

void	init_sem(t_info *info)
{
	destroy_semaphores();
	info->forks = sem_open("./forks", O_CREAT,
			S_IRWXG, info->num_of_philos);
	info->is_died = sem_open("./is_died", O_CREAT,
			S_IRWXG, 0);
	info->typing = sem_open("./typing", O_CREAT,
			S_IRWXG, 1);
	if (info->forks == SEM_FAILED || info->is_died == SEM_FAILED)
	{
		printf("Error! Sem_Open");
		exit(-1);
	}
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc < 5 || argc > 6)
	{
		printf("\n\033[0;31mError: \033[0mInvalid number of arguments\n\n");
		printf("\033[0;32mUsage: \033[0m");
		printf("./philo <number_of_philosophers> <time_to_die>");
		printf(" <time_to_eat> <time_to_sleep>");
		printf(" [number_of_times_each_philosopher_must_eat]\n\n");
		printf("\033[0;33mExample: \033[0m./philo 5 800 200 200 3\n\n");
		return (-1);
	}
	init(argc, argv, &info);
	init_philo(&info);
	init_sem(&info);
	process(&info);
	sem_wait(info.is_died);
	destroy(&info);
	return (0);
}
