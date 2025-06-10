/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:32:24 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/10 15:45:54 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	check_init(t_prog *prog)
{
	if (prog->num_of_philos < 1 || prog->num_of_philos > 200)
		return (1);
	if (prog->time_to_die < 60)
		return (1);
	if (prog->time_to_eat < 60)
		return (1);
	if (prog->time_to_sleep < 60)
		return (1);
	if (prog->meals_to_have == 0 && prog->limit_meals)
		return (1);
	return (0);
}
