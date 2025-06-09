/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:05:00 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/09 16:16:53 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	print_status(t_philo *philo, t_program *program, char *message)
{
	long	time_taken;

	time_taken = get_time(MILLISECOND) - program->simulation_start;
	pthread_mutex_lock(&program->print_lock);
	if (!get_bool(&program->simulation_end_lock, &program->simulation_has_ended))
		printf("%ld %d %s\n", time_taken, philo->id, message);
	pthread_mutex_unlock(&program->print_lock);
}
