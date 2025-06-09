/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:03:13 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/09 21:23:31 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	start_eating(t_philo *philo, t_program *program)
{
	(void)program;
	pthread_mutex_lock(&philo->first_fork->fork);
	print_status(philo, program, "has taken a fork");
	pthread_mutex_lock(&philo->second_fork->fork);
	print_status(philo, program, "has taken a fork");
	set_long(&philo->last_meal_lock, &philo->last_meal, get_time(MILLISECOND));
	set_long(&philo->meal_lock, &philo->meals_eaten, philo->meals_eaten + 1);
	print_status(philo, program, "is eating");
	precise_sleep(program->time_to_eat * 1e3);
	pthread_mutex_unlock(&philo->first_fork->fork);
	pthread_mutex_unlock(&philo->second_fork->fork);
}
