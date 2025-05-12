/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:25:52 by pchennia          #+#    #+#             */
/*   Updated: 2024/06/06 14:42:08 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/time.h>

// COLORS
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define CYAN	"\033[0;36m"
# define BOLD	"\033[0;1m"
# define X	"\033[0;0m"

typedef struct s_info	t_info;
typedef struct s_philo
{
	int				id;
	int				ate_count;
	int				fork_r;
	int				fork_l;
	bool			done;
	uint64_t		last_ate;
	pthread_t		th_id;
	t_info			*info;
}				t_philo;

typedef struct s_info
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				count_done;
	bool			is_running;
	uint64_t		start_time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
}				t_info;

// Routines
void		*routine(void *arg);
void		*routine_checker(void *arg);

//  helper functions
void		destroy_threads(t_info *info);
void		destroy_mutexes(t_info *info);
uint64_t	get_time_ms(void);
int			ft_atoi(const char *str);

// Actions
void		take_forks(t_philo *philo);
void		leave_forks(t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);

#endif
