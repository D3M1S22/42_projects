/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku < dshushku@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:00:12 by dshushku          #+#    #+#             */
/*   Updated: 2023/11/09 17:06:27 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int message(int id, char *act, t_config *config, int d)
{
	if (d)
		return (0);
	pt_mutex_lock(&config->print_lock);
	printf("%lld %d %s\n", (now_ts() - config->start_time), id, act);
	pt_mutex_unlock(&config->print_lock);
	return (0);
}

pthread_t *start(t_config *config, t_philo *philos, int n_philo)
{
	int i;
	pthread_t *threads;

	i = -1;
	config->start_time = now_ts() + (config->n_philo * 2 * 10);
	threads = (pthread_t *)malloc(sizeof(pthread_t) * n_philo);
	while (++i < n_philo)
	{
		philos[i].last_meal = config->start_time;
		pthread_create(&threads[i], (void *)0, &work, &philos[i]);
	}
	return (threads);
}

int _close(t_config *c, t_philo *p, pthread_t *t, char *msg)
{
	int i;

	if (t)
		free(t);
	if (p)
		destroy_mutexes(p[0].forks, p, c->n_philo);
	if (c)
		free(c);
	if (msg)
	{
		i = -1;
		while (msg[++i])
			continue;
		write(1, msg, i);
	}
	return (1);
}

void start_controller(t_config *config, t_philo *philos, pthread_t *threads)
{
	int i;
	pthread_t t;
	t_send send;

	i = -1;
	send.config = config;
	send.philos = philos;
	pthread_create(&t, (void *)0, &controller, &send);
	while (++i < config->n_philo)
		pthread_join(threads[i], (void *)0);
	i = -1;
	// while (++i < config->n_philo)
	pthread_join(t, (void *)0);
}

int main(int argc, char *argv[])
{
	t_config *config;
	t_philo *philos;
	pthread_mutex_t *forks;
	pthread_t *threads;

	if (argc < 5)
		return (_close((void *)0, (void *)0, (void *)0, "not enough args\n"));
	config = (t_config *)malloc(sizeof(t_config));
	if (!config)
		return (_close((void *)0, (void *)0, (void *)0, "config error\n"));
	if (args_parser(config, argc, argv))
		return (_close(config, (void *)0, (void *)0, "args error\n"));
	philos = (t_philo *)malloc(config->n_philo * sizeof(t_philo));
	if (!philos)
		return (_close(config, (void *)0, (void *)0, "philo error\n"));
	forks = malloc(config->n_philo * sizeof(pthread_mutex_t));
	if (!forks)
		return (_close(config, (void *)0, (void *)0, "forks error\n"));
	init_philoers(config, philos, forks);
	threads = start(config, philos, config->n_philo);
	start_controller(config, philos, threads);
	return (_close(config, philos, threads, (void *)0));
}
