/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mallocs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:48:53 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/10 15:51:16 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	destroy_mallocs(t_prog *prog)
{
	int		index;
	t_philo	*philo;

	index = -1;
	while (++index < prog->num_of_philos)
	{
		philo = prog->philos + index;
		pthread_mutex_destroy(&philo->meal_lock);
		pthread_mutex_destroy(&philo->last_meal_lock);
		pthread_mutex_destroy(&prog->forks[index].fork);
	}
	pthread_mutex_destroy(&prog->threads_ready_lock);
	pthread_mutex_destroy(&prog->threads_running_lock);
	pthread_mutex_destroy(&prog->sim_end_lock);
	pthread_mutex_destroy(&prog->print_lock);
	free(prog->forks);
	free(prog->philos);
}
