/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:44:16 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/10 15:56:29 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long	get_time(t_time_measurement time_measurement)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (time_measurement == SECONDS)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
	else if (time_measurement == MILLI)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (time_measurement == MICRO)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	else
		return (-1);
}
