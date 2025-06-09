/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:28:09 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/09 15:28:46 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long	get_long(pthread_mutex_t *lock, long *dest)
{
	long	ret_val;

	pthread_mutex_lock(lock);
	ret_val = *dest;
	pthread_mutex_unlock(lock);
	return (ret_val);
}