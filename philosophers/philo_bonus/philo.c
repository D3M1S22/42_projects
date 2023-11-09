/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku < dshushku@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:00:52 by dshushku          #+#    #+#             */
/*   Updated: 2023/11/09 17:02:43 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int control_philo(t_philo *philo, t_config *config)
{
	if (config->stop)
		return (config->stop);
	sem_wait(config->check);
	if (now_ts() - philo->last_meal > config->t_die)
	{
		message(philo->id, DIED, config, config->stop);
		sem_wait(config->print_lock);
		config->stop = 1;
		exit(1);
	}
	sem_post(config->check);
	return (config->stop);
}

void *controller(void *args)
{
	t_philo *philo;

	philo = (t_philo *)args;
	if (philo->config->n_philo == 1)
		return (0);
	wait_start(philo->config->start_time);
	while (!philo->config->stop)
	{
		if (control_philo(philo, philo->config))
			break;
		if (philo->full)
			break;
		usleep(1000);
	}
	return (0);
}

void lone_philo(t_philo *philo)
{
	message(philo->id, THINKING, philo->config, philo->config->stop);
	alone_philo_run(philo);
	message(philo->id, DIED, philo->config, philo->config->stop);
	exit(0);
}

void work(void *args)
{
	pthread_t d;
	t_philo *philo;
	unsigned long st;

	philo = (t_philo *)args;
	st = philo->config->start_time;
	philo->last_meal = st;
	pthread_create(&d, (void *)0, &controller, philo);
	wait_start(st);
	if (!(philo->id % 2))
		ft_sleep(200);
	if (philo->config->n_philo == 1)
		lone_philo(philo);
	while (!philo->config->stop)
	{
		message(philo->id, THINKING, philo->config, philo->config->stop);
		philo_run(philo);
		if (philo->full)
			break;
	}
	pthread_join(d, (void *)0);
	exit(0);
}

void init_philoers(t_config *config, t_philo *philos, sem_t *forks)
{
	int i;

	i = -1;
	while (++i < config->n_philo)
	{
		philos[i].forks = forks;
		philos[i].id = i + 1;
		philos[i].meals_counter = 0;
		philos[i].full = 0;
		philos[i].config = config;
	}
}
