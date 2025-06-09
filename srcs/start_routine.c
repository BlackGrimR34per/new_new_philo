/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:20:44 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/09 21:43:19 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static	void	increment_running_threads(t_program *program, long *dest)
{
	pthread_mutex_lock(&program->threads_running_lock);
	(*dest)++;
	pthread_mutex_unlock(&program->threads_running_lock);
}

// RETURN NULL IF FINISH?, can add incremenet running threads to synchornize better
void	*start_routine(void *args)
{
	t_philo		*philo;
	t_program	*program;

	philo = (t_philo *)args;
	program = philo->program;

	if (program->num_of_philos == 1)
		return (handle_one_philo(philo, program));
	else
	{
		threads_ready(program);
		// set_long(&program->threads_running_lock, &program->threads_running, program->threads_running + 1);
		increment_running_threads(program, &program->threads_running);
		set_long(&philo->last_meal_lock, &philo->last_meal, get_time(MILLISECOND));
		// while (!get_bool(&program->simulation_end_lock, &program->simulation_has_ended))
		// {
		// 	start_eating(philo, program);
		// 	start_sleeping(philo, program);
		// 	start_thinking(philo, program);
		// }
	}
	return (NULL);
}
