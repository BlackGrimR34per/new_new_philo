/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_threads_ready.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:19:18 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/10 15:47:37 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	wait_threads_ready(t_prog *prog)
{
	while (!get_bool(&prog->threads_ready_lock, &prog->threads_ready))
		;
}
