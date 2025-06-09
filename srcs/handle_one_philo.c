/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_one_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:01:45 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/09 21:04:14 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*handle_one_philo(t_philo *philo, t_program *program)
{
	pthread_mutex_lock(&philo->first_fork->fork);
	print_status(philo, program, "has taken a fork");
	precise_sleep(program->time_to_die * 1e3);
	print_status(philo, program, "has died");
	pthread_mutex_unlock(&philo->first_fork->fork);
	set_bool(&program->simulation_end_lock, &program->simulation_has_ended, true);
	return (NULL);
}
