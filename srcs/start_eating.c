/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:03:13 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/10 18:45:42 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	start_eating(t_philo *philo, t_prog *prog)
{
	pthread_mutex_lock(&philo->first_fork->fork);
	print_status(philo, prog, YELLOW "has taken a fork" RST);
	pthread_mutex_lock(&philo->second_fork->fork);
	print_status(philo, prog, YELLOW "has taken a fork" RST);
	set_long(&philo->last_meal_lock, &philo->last_meal, get_time(MILLI));
	set_long(&philo->meal_lock, &philo->meals_eaten, philo->meals_eaten + 1);
	print_status(philo, prog, GREEN "is eating" RST);
	precise_sleep(prog->time_to_eat * 1000, prog);
	pthread_mutex_unlock(&philo->second_fork->fork);
	pthread_mutex_unlock(&philo->first_fork->fork);
}
