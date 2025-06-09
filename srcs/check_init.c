/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:32:24 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/09 15:16:21 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	check_init(t_program *program)
{
	if (program->num_of_philos < 1 || program->num_of_philos > 200)
		return (1);
	if (program->time_to_die < 60)
		return (1);
	if (program->time_to_eat < 60)
		return (1);
	if (program->time_to_sleep < 60)
		return (1);
	if (program->meals_to_have == 0 && program->limit_meals)
		return (1);
	return (0);
}
