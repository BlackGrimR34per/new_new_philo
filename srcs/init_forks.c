/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:57:23 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/10 15:46:31 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	init_forks(t_prog *prog)
{
	int	index;

	index = -1;
	prog->forks = malloc(sizeof(t_fork) * prog->num_of_philos);
	while (++index < prog->num_of_philos)
	{
		prog->forks[index].id = index;
		pthread_mutex_init(&prog->forks[index].fork, NULL);
	}
}
