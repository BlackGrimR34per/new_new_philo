/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sleeping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:13:14 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/09 16:33:31 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	start_sleeping(t_philo *philo, t_program *program)
{
	print_status(philo, program, "is sleeping");
	precise_sleep(program->time_to_sleep * 1e3);
}
