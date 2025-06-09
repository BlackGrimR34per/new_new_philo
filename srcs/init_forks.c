/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:57:23 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/09 14:04:08 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	init_forks(t_program *program)
{
	int	index;

	index = -1;
	program->forks = malloc(sizeof(t_fork) * program->num_of_philos);
	while (++index < program->num_of_philos)
	{
		program->forks[index].id = index;
		pthread_mutex_init(&program->forks[index].fork, NULL);
	}
}
