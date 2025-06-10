/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sleeping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:13:14 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/10 18:45:14 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	start_sleeping(t_philo *philo, t_prog *prog)
{
	print_status(philo, prog, BLUE "is sleeping" RST);
	precise_sleep(prog->time_to_sleep * 1000, prog);
}
