/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku < dshushku@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:00:06 by dshushku          #+#    #+#             */
/*   Updated: 2023/11/09 17:03:05 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philo_run(t_philo *philo)
{
	pt_mutex_lock(&philo->forks[philo->fork_ids[0]]);
	message(philo->id, FORK_TOOK, philo->config, philo->config->stop);
	pt_mutex_lock(&philo->forks[philo->fork_ids[1]]);
	message(philo->id, FORK_TOOK, philo->config, philo->config->stop);
	message(philo->id, EATING, philo->config, philo->config->stop);
	pt_mutex_lock(&philo->rw_mutex);
	philo->last_meal = now_ts();
	(philo->meals_counter)++;
	if (philo->meals_counter == philo->config->tme)
		philo->full = 1;
	pt_mutex_unlock(&philo->rw_mutex);
	ft_sleep(philo->config->t_eat);
	pt_mutex_unlock(&philo->forks[philo->fork_ids[0]]);
	pt_mutex_unlock(&philo->forks[philo->fork_ids[1]]);
	message(philo->id, SLEEPING, philo->config, philo->config->stop);
	ft_sleep(philo->config->t_sleep);
}

void alone_philo_run(t_philo *philo)
{
	pt_mutex_lock(&philo->forks[philo->fork_ids[0]]);
	message(philo->id, FORK_TOOK, philo->config, philo->config->stop);
	ft_sleep(philo->config->t_die);
}
