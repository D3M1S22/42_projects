/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku < dshushku@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:00:20 by dshushku          #+#    #+#             */
/*   Updated: 2023/11/09 17:06:02 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void destroy_mutexes(pthread_mutex_t *forks, t_philo *philos, int n_philo)
{
	int i;

	i = -1;
	while (++i < n_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		pthread_mutex_destroy(&philos[i].rw_mutex);
	}
	free(forks);
	free(philos);
}

int control_philos(t_philo *philos, t_config *config)
{
	int i;
	int r;

	i = -1;
	r = 1;
	while (++i < config->n_philo)
	{
		if (config->stop)
			break;
		pt_mutex_lock(&philos[i].rw_mutex);
		if (now_ts() - philos[i].last_meal > config->t_die)
		{
			message(i + 1, DIED, config, config->stop);
			config->stop = 1;
		}
		if (!philos[i].full)
			r = 0;
		pt_mutex_unlock(&philos[i].rw_mutex);
	}
	if (r)
		return (r);
	return (config->stop);
}

void *controller(void *args)
{
	t_send *send;

	send = (t_send *)args;
	wait_start(send->config->start_time);
	while (1)
	{
		if (control_philos(send->philos, send->config))
			break;
		usleep(1000);
	}
	return (0);
}

void *work(void *args)
{
	t_philo *philo;
	unsigned long st;

	philo = (t_philo *)args;
	st = philo->config->start_time;
	wait_start(st);
	if (!(philo->id % 2))
		ft_sleep(200);
	if (philo->config->n_philo == 1)
	{
		message(philo->id, THINKING, philo->config, philo->config->stop);
		alone_philo_run(philo);
		return ((void *)0);
	}
	while (!philo->config->stop)
	{
		message(philo->id, THINKING, philo->config, philo->config->stop);
		philo_run(philo);
		if (philo->full)
			break;
	}
	return ((void *)0);
}

void init_philoers(t_config *config, t_philo *philos, pthread_mutex_t *forks)
{
	int i;

	i = -1;
	while (++i < config->n_philo)
	{
		pthread_mutex_init(&forks[i], (void *)0);
		pthread_mutex_init(&philos[i].rw_mutex, (void *)0);
		philos[i].forks = forks;
		philos[i].id = i + 1;
		philos[i].fork_ids[0] = i;
		philos[i].fork_ids[1] = (i + 1) % config->n_philo;
		philos[i].n_meals = 0;
		philos[i].full = 0;
		philos[i].config = config;
	}
}
