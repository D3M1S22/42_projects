/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku < dshushku@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:00:37 by dshushku          #+#    #+#             */
/*   Updated: 2023/11/09 17:03:05 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_run(t_philo *philo)
{
	sem_wait(philo->forks);
	message(philo->id, FORK_TOOK, philo->config, philo->config->stop);
	sem_wait(philo->forks);
	message(philo->id, FORK_TOOK, philo->config, philo->config->stop);
	message(philo->id, EATING, philo->config, philo->config->stop);
	sem_wait(philo->config->check);
	philo->last_meal = now_ts();
	(philo->meals_counter)++;
	if (philo->meals_counter == philo->config->tme)
		philo->full = 1;
	sem_post(philo->config->check);
	ft_sleep(philo->config->t_eat);
	message(philo->id, SLEEPING, philo->config, philo->config->stop);
	sem_post(philo->forks);
	sem_post(philo->forks);
	ft_sleep(philo->config->t_sleep);
}

void	alone_philo_run(t_philo *philo)
{
	sem_wait(philo->forks);
	message(philo->id, FORK_TOOK, philo->config, philo->config->stop);
	ft_sleep(philo->config->t_die);
}
