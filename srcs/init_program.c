/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 08:22:32 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/09 21:34:53 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

//SOME ARE REDUNDANT SETS
void	init_program(int argc, char *argv[], t_program *program)
{
	memset(program, 0, sizeof(t_program));
	program->num_of_philos = ft_atol(argv[1]);
	program->time_to_die = ft_atol(argv[2]);
	program->time_to_eat = ft_atol(argv[3]);
	program->time_to_sleep = ft_atol(argv[4]);
	program->threads_running = 0;
	program->limit_meals = false;
	program->threads_ready = false;
	program->simulation_has_ended = false;
	pthread_mutex_init(&program->print_lock, NULL);
	pthread_mutex_init(&program->threads_ready_lock, NULL);
	pthread_mutex_init(&program->threads_running_lock, NULL);
	pthread_mutex_init(&program->simulation_end_lock, NULL);
	if (argc == 6)
	{
		program->limit_meals = true;
		program->meals_to_have = ft_atol(argv[5]);
	}
}
