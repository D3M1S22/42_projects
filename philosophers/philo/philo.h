/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku < dshushku@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:00:25 by dshushku          #+#    #+#             */
/*   Updated: 2023/11/09 17:06:27 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define FORK_TOOK "has taken a fork"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define DIED "died"

typedef struct s_config
{
	long long		start_time;
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				tme;
	int				stop;
	pthread_mutex_t	print_lock;
}	t_config;

typedef struct s_philo
{
	int				id;
	int				fork_ids[2];
	int				n_meals;
	int				full;
	long long		last_meal;
	t_config		*config;
	pthread_mutex_t	rw_mutex;
	pthread_mutex_t	*forks;
}	t_philo;

typedef struct s_send
{
	t_config	*config;
	t_philo		*philos;
}	t_send;

int			args_parser(t_config *config, int argc, char *argv[]);
int			message(int id, char *act, t_config *config, int d);
int			ft_atoi(char *str);
long long	now_ts(void);
void		ft_sleep(int ms);
void		init_philoers(t_config *config,	t_philo *philos,
				pthread_mutex_t *forks);
void		*work(void *arguments);
void		philo_run(t_philo *philo);
void		alone_philo_run(t_philo *philo);
void		*controller(void *args);
void		wait_start(long long st);
void		destroy_mutexes(pthread_mutex_t *forks, t_philo *philos,
				int n_philo);

#endif
