/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:30:15 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/09 15:30:34 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	set_long(pthread_mutex_t *lock, long *dest, long value)
{
	pthread_mutex_lock(lock);
	*dest = value;
	pthread_mutex_unlock(lock);
}