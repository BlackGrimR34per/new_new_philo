/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 08:30:05 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/10 15:55:47 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

// MIGHT BREAK FOR ONE PHILO
void	assign_forks(t_philo *philo, t_prog *prog, int index)
{
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &prog->forks[index];
		philo->second_fork = &prog->forks[(index + 1)
			% prog->num_of_philos];
	}
	else
	{
		philo->first_fork = &prog->forks[(index + 1)
			% prog->num_of_philos];
		philo->second_fork = &prog->forks[index];
	}
}

void	init_philos(t_prog *prog)
{
	int		index;
	t_philo	*philo;

	index = -1;
	prog->philos = malloc(sizeof(t_philo) * prog->num_of_philos);
	while (++index < prog->num_of_philos)
	{
		philo = &prog->philos[index];
		philo->id = index + 1;
		philo->meals_eaten = 0;
		philo->last_meal = 0;
		philo->prog = prog;
		assign_forks(philo, prog, index);
		pthread_mutex_init(&philo->meal_lock, NULL);
		pthread_mutex_init(&philo->last_meal_lock, NULL);
		pthread_create(&philo->thread, NULL, start_routine, philo);
	}
	prog->sim_start = get_time(MILLI);
	set_bool(&prog->threads_ready_lock, &prog->threads_ready, true);
	pthread_create(&prog->monitor_thread, NULL, start_monitoring, prog);
	index = -1;
	while (++index < prog->num_of_philos)
		pthread_join(prog->philos[index].thread, NULL);
	pthread_join(prog->monitor_thread, NULL);
}
