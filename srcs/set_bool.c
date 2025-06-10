/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:28:57 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/10 15:33:45 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	set_bool(pthread_mutex_t *lock, bool *dest, bool value)
{
	pthread_mutex_lock(lock);
	*dest = value;
	pthread_mutex_unlock(lock);
}
