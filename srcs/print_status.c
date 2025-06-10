/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:05:00 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/10 15:55:49 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	print_status(t_philo *philo, t_prog *prog, char *message)
{
	long	time_taken;

	pthread_mutex_lock(&prog->print_lock);
	time_taken = get_time(MILLI) - prog->sim_start;
	if (!get_bool(&prog->sim_end_lock, &prog->sim_has_ended))
		printf("%ld %d %s\n", time_taken, philo->id, message);
	pthread_mutex_unlock(&prog->print_lock);
}
