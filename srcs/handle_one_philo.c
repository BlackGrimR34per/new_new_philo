/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_one_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:01:45 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/10 15:51:29 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*handle_one_philo(t_philo *philo, t_prog *prog)
{
	pthread_mutex_lock(&philo->first_fork->fork);
	print_status(philo, prog, "has taken a fork");
	precise_sleep(prog->time_to_die * 1000, prog);
	print_status(philo, prog, "has died");
	pthread_mutex_unlock(&philo->first_fork->fork);
	set_bool(&prog->sim_end_lock,
		&prog->sim_has_ended, true);
	return (NULL);
}
