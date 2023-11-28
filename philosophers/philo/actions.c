/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:37:36 by dshushku          #+#    #+#             */
/*   Updated: 2023/11/28 14:16:07 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	phlio_run(t_philo *philo)
{
	pthread_mutex_lock(&philo->forks[philo->fork_ids[0]]);
	message(philo->id, FORK_TAKEN, philo->config, philo->config->stop);
	pthread_mutex_lock(&philo->forks[philo->fork_ids[1]]);
	message(philo->id, FORK_TAKEN, philo->config, philo->config->stop);
	message(philo->id, EATING, philo->config, philo->config->stop);
	pthread_mutex_lock(&philo->rw_mutex);
	philo->last_meal = now_ts();
	(philo->n_meals)++;
	if (philo->n_meals == philo->config->tme)
		philo->full = 1;
	pthread_mutex_unlock(&philo->rw_mutex);
	ft_c_sleep(philo->config->t_eat);
	pthread_mutex_unlock(&philo->forks[philo->fork_ids[0]]);
	pthread_mutex_unlock(&philo->forks[philo->fork_ids[1]]);
	message(philo->id, SLEEPING, philo->config, philo->config->stop);
	ft_c_sleep(philo->config->t_sleep);
}

void	alone_philo_run(t_philo *philo)
{
	pthread_mutex_lock(&philo->forks[philo->fork_ids[0]]);
	message(philo->id, FORK_TAKEN, philo->config, philo->config->stop);
	ft_c_sleep(philo->config->t_die);
}
