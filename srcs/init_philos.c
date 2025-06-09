/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 08:30:05 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/09 21:36:49 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	assign_forks(t_philo *philo, t_program *program, int index)
{
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &program->forks[index];
		philo->second_fork = &program->forks[(index + 1)
			% program->num_of_philos];
	}
	else
	{
		philo->first_fork = &program->forks[(index + 1)
			% program->num_of_philos];
		philo->second_fork = &program->forks[index];
	}
}

void	init_philos(t_program *program)
{
	int		index;
	t_philo	*philo;

	index = -1;
	program->philos = malloc(sizeof(t_philo) * program->num_of_philos);
	while (++index < program->num_of_philos)
	{
		philo = &program->philos[index];
		philo->id = index + 1;
		philo->meals_eaten = 0;
		philo->last_meal = 0;
		philo->program = program;
		assign_forks(philo, program, index);
		pthread_mutex_init(&philo->meal_lock, NULL);
		pthread_mutex_init(&philo->last_meal_lock, NULL);
		pthread_create(&philo->thread, NULL, start_routine, philo);
	}
	// pthread_create(&program->monitor_thread, NULL, start_monitoring, program);
	program->simulation_start = get_time(MILLISECOND);
	set_bool(&program->threads_ready_lock, &program->threads_ready, true);
	index = -1;
	while (++index < program->num_of_philos)
		pthread_join(program->philos[index].thread, NULL);
	// pthread_join(program->monitor_thread, NULL);
}
