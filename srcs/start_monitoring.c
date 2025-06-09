/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_monitoring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:25:30 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/09 21:25:31 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static int	philos_has_eaten(t_program *program)
{
	int		index;
	long	meals_had;

	index = -1;
	if (!program->limit_meals)
		return (0);
	while (++index < program->num_of_philos)
	{
		meals_had = get_long(&program->philos[index].meal_lock, &program->philos[index].meals_eaten);
		if (meals_had < program->meals_to_have)
			return (0);
	}
	return (1);
}

void	*start_monitoring(void	*args)
{
	int			index;
	long		last_meal;
	t_philo		*philo;
	t_program	*program;

	program = (t_program *)args;
	while (!get_bool(&program->simulation_end_lock, &program->simulation_has_ended))
	{
		index = -1;
		while (++index < program->num_of_philos)
		{
			philo = program->philos + index;
			last_meal = get_long(&philo->last_meal_lock, &philo->last_meal);
			if (get_time(MILLISECOND) - last_meal > program->time_to_die)
			{
				print_status(&program->philos[index], program, "has died");
				set_bool(&program->simulation_end_lock, &program->simulation_has_ended, true);
			}
			if (philos_has_eaten(program))
				set_bool(&program->simulation_end_lock, &program->simulation_has_ended, true);
		}
		precise_sleep(200);
	}
	return (NULL);
}
