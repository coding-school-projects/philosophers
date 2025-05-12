/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:25:23 by pchennia          #+#    #+#             */
/*   Updated: 2024/06/06 15:56:41 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>
# include <stdint.h>
# include <signal.h>
# include <fcntl.h>

// COLORS
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define CYAN	"\033[0;36m"
# define BOLD	"\033[0;1m"
# define X	"\033[0;0m"

typedef struct s_info	t_info;
typedef struct s_philo
{
	int				pid;
	int				id;
	int				ate_count;
	uint64_t		last_ate;
	t_info			*info;
}				t_philo;

typedef struct s_info
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	uint64_t		start_time;
	pthread_t		is_running;
	t_philo			*philos;
	sem_t			*forks;
	sem_t			*is_died;
	sem_t			*typing;
}				t_info;

// Routine
void		process(t_info *info);
void		routine(t_philo *philo);
void		*routine_checker(void *arg);
void		*wait_process(void *arg);

//actions
void		take_forks(t_philo *philo);
void		leave_forks(t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);

// Helper functions
int			ft_atoi(const char *str);
uint64_t	get_time_ms(void);
void		destroy_semaphores(void);
void		destroy(t_info *info);

#endif