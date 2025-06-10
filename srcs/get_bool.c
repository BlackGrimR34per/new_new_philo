/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:25:55 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/09 15:28:04 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

bool	get_bool(pthread_mutex_t *lock, bool *dest)
{
	bool	ret_val;

	pthread_mutex_lock(lock);
	ret_val = *dest;
	pthread_mutex_unlock(lock);
	return (ret_val);
}
