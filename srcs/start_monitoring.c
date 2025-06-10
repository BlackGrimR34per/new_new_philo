/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_monitoring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:25:30 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/10 20:47:03 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static int	philos_has_eaten(t_prog *prog)
{
	int		index;
	long	meals_had;

	index = -1;
	if (!prog->limit_meals)
		return (0);
	while (++index < prog->num_of_philos)
	{
		meals_had = get_long(&prog->philos[index].meal_lock,
				&prog->philos[index].meals_eaten);
		if (meals_had < prog->meals_to_have)
			return (0);
	}
	return (1);
}

void	*start_monitoring(void	*args)
{
	int		index;
	long	last_meal;
	t_prog	*prog;

	prog = (t_prog *)args;
	wait_threads_running(prog);
	while (!get_bool(&prog->sim_end_lock, &prog->sim_has_ended))
	{
		index = -1;
		while (++index < prog->num_of_philos)
		{
			last_meal = get_long(&prog->philos[index].last_meal_lock,
					&prog->philos[index].last_meal);
			if (philos_has_eaten(prog))
				set_bool(&prog->sim_end_lock, &prog->sim_has_ended, true);
			if (get_time(MILLI) - last_meal > prog->time_to_die)
			{
				print_status(&prog->philos[index], prog, RED "has died" RST);
				set_bool(&prog->sim_end_lock, &prog->sim_has_ended, true);
				prog->philo_dieded = true;
			}
		}
		precise_sleep(100, prog);
	}
	return (NULL);
}
