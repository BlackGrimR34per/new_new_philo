/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precise_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:36:57 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/09 16:25:33 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	precise_sleep(long usec)
{
	long	start;
	long	elapsed;
	long	remainder;

	start = get_time(MICROSECONDS);
	while (get_time(MICROSECONDS) - start < usec)
	{
		// if (get_bool(&util->simulation_end_lock, &util->simulation_has_ended))
		// 	break ;
		elapsed = get_time(MICROSECONDS) - start;
		remainder = usec - elapsed;
		if (remainder > 1e3)
			usleep(remainder / 2);
		else
		{
			while (get_time(MICROSECONDS) - start < usec)
				;
		}
	}
}
