/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_thinking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:20:57 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/21 17:06:27 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	start_thinking(t_philo *philo, t_prog *prog)
{
	long	time_to_eat;
	long	time_to_sleep;
	long	time_to_think;

	print_status(philo, prog, CYAN "is thinking" RST);
	if (prog->num_of_philos % 2 == 0)
		return ;
	time_to_eat = prog->time_to_eat;
	time_to_sleep = prog->time_to_sleep;
	time_to_think = time_to_eat * 2 - time_to_sleep;
	if (time_to_think < 0)
		time_to_think = 0;
	precise_sleep(time_to_think * 1000, prog);
}
