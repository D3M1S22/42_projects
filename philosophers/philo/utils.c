/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku < dshushku@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:00:30 by dshushku          #+#    #+#             */
/*   Updated: 2023/11/09 17:00:31 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_atoi(char *str)
{
	int sign;
	int r;
	int i;

	r = 0;
	i = 0;
	sign = 1;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return (r * sign);
}

long long now_ts(void)
{
	struct timeval current_time;
	long long t;

	gettimeofday(&current_time, (void *)0);
	t = (current_time.tv_sec) * 1000 + (current_time.tv_usec) / 1000;
	return (t);
}

void wait_start(long long st)
{
	while (now_ts() < st)
		continue;
}

int parse_args(t_config *config, int argc, char *argv[])
{
	int i;
	int c;

	i = 0;
	while (++i < argc)
	{
		c = -1;
		while (argv[i][++c])
			if (!(argv[i][c] >= '0' && argv[i][c] <= '9'))
				return (1);
	}
	config->stop = 0;
	config->n_philo = ft_atoi(argv[1]);
	config->t_die = ft_atoi(argv[2]);
	config->t_eat = ft_atoi(argv[3]);
	config->t_sleep = ft_atoi(argv[4]);
	config->tme = -1;
	if (argc == 6)
		config->tme = ft_atoi(argv[5]);
	pthread_mutex_init(&config->print_lock, (void *)0);
	return (0);
}

void ft_sleep(int ms)
{
	long long f;

	f = now_ts() + ms;
	while (now_ts() < f)
		usleep(100);
}
