/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_threads_running.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:11:14 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/10 15:45:43 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	wait_threads_running(t_prog *prog)
{
	while (get_long(&prog->threads_running_lock, &prog->threads_running)
		!= prog->num_of_philos)
		;
}
