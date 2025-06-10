/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stagger_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:18:57 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/10 15:47:25 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	stagger_threads(t_philo *philo, t_prog *prog)
{
	if (prog->num_of_philos % 2 == 0)
	{
		if (philo->id % 2 == 0)
			precise_sleep((prog->time_to_sleep / 2) * 1000, prog);
	}
	else
	{
		if (philo->id % 2)
			start_thinking(philo, prog);
	}
}
