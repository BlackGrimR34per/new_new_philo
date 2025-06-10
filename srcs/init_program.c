/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 08:22:32 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/10 18:56:58 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

//SOME ARE REDUNDANT SETS
void	init_prog(int argc, char *argv[], t_prog *prog)
{
	memset(prog, 0, sizeof(t_prog));
	prog->num_of_philos = ft_atol(argv[1]);
	prog->time_to_die = ft_atol(argv[2]);
	prog->time_to_eat = ft_atol(argv[3]);
	prog->time_to_sleep = ft_atol(argv[4]);
	prog->threads_running = 0;
	prog->limit_meals = false;
	prog->threads_ready = false;
	prog->sim_has_ended = false;
	prog->philo_dieded = false;
	pthread_mutex_init(&prog->print_lock, NULL);
	pthread_mutex_init(&prog->threads_ready_lock, NULL);
	pthread_mutex_init(&prog->threads_running_lock, NULL);
	pthread_mutex_init(&prog->sim_end_lock, NULL);
	if (argc == 6)
	{
		prog->limit_meals = true;
		prog->meals_to_have = ft_atol(argv[5]);
	}
}
