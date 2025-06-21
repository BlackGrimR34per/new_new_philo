/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precise_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:36:57 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/21 17:27:13 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

// if (get_bool(&prog->sim_end_lock, &prog->sim_has_ended))
// 			return ;
// 	usleep(usec);
void	precise_sleep(long usec, t_prog *prog)
{
	long	start;
	long	elapsed;
	long	remainder;

	start = get_time(MICRO);
	while (get_time(MICRO) - start < usec)
	{
		if (get_bool(&prog->sim_end_lock,
				&prog->sim_has_ended))
			break ;
		elapsed = get_time(MICRO) - start;
		remainder = usec - elapsed;
		if (remainder > 1000)
			usleep(remainder / 2);
		else
		{
			while (get_time(MICRO) - start < usec)
				;
		}
	}
}
