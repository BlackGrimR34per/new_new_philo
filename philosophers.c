/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 08:09:56 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/10 18:58:48 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_prog	prog;

	if (argc != 5 && argc != 6)
		return (print_error(INVALID_ARGS));
	if (check_input(argc, argv) == -1)
		return (print_error(INVALID_ARG_FORMAT));
	init_prog(argc, argv, &prog);
	if (check_init(&prog))
		return (print_error(INVALID_ARG_VALUE));
	init_forks(&prog);
	init_philos(&prog);
	destroy_mallocs(&prog);
	if (prog.limit_meals && prog.philo_dieded == false)
		printf(MAGENTA "Philo's has eaten at least %ld\n" RST, prog.meals_to_have);
	printf(WHITE "Simulation has ended\n" RST);
}
