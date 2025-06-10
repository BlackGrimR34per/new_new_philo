/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:20:44 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/10 20:24:21 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static	void	increment_running_threads(t_prog *prog, long *dest)
{
	pthread_mutex_lock(&prog->threads_running_lock);
	(*dest)++;
	pthread_mutex_unlock(&prog->threads_running_lock);
}

void	*start_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->prog->num_of_philos == 1)
	{
		wait_threads_ready(philo->prog);
		set_long(&philo->last_meal_lock, &philo->last_meal, get_time(MILLI));
		increment_running_threads(philo->prog, &philo->prog->threads_running);
		handle_one_philo(philo, philo->prog);
	}
	else
	{
		wait_threads_ready(philo->prog);
		set_long(&philo->last_meal_lock, &philo->last_meal, get_time(MILLI));
		increment_running_threads(philo->prog, &philo->prog->threads_running);
		// stagger_threads(philo, philo->prog);
		while (!get_bool(&philo->prog->sim_end_lock,
				&philo->prog->sim_has_ended))
		{
			start_eating(philo, philo->prog);
			start_sleeping(philo, philo->prog);
			start_thinking(philo, philo->prog);
		}
	}
	return (NULL);
}
