/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:38:27 by dshushku          #+#    #+#             */
/*   Updated: 2023/11/28 14:17:00 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/time.h>
# include <pthread.h>

# define FORK_TAKEN "has taken a fork"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define DIED "died"
# define S_FORKS "/S_FORKS"
# define S_CHECK "/S_CHECK"
# define S_PRINT "/S_PRINT"

typedef struct s_config
{
	long long	start_time;
	int			n_philo;
	int			t_die;
	int			t_eat;
	int			t_sleep;
	int			tme;
	int			stop;
	int			full_count;
	sem_t		*print_lock;
	sem_t		*check;
}	t_config;

typedef struct s_philo
{
	int			id;
	pid_t		proc;
	int			n_meals;
	int			full;
	long long	last_meal;
	t_config	*config;
	sem_t		*forks;
}	t_philo;

int			args_parser(t_config *config, int argc, char *argv[]);
int			message(int id, char *act, t_config *config, int d);
int			ft_atoi(char *str);
long long	now_ts(void);
void		ft_c_sleep(int ms);
void		config_philos(t_config *config, t_philo *philos, sem_t *forks);
void		work(void *arguments);
void		philo_run(t_philo *philo);
void		alone_philo_run(t_philo *philo);
void		*controller(void *args);
void		await_start(long long st);
void		destroy_mutexes(pthread_mutex_t *forks, t_philo *philos,
				int n_philo);

#endif
