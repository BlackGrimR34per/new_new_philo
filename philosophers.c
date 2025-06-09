/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 08:09:56 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/09 21:41:51 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_program	program;

	if (argc != 5 && argc != 6)
		return (print_error(INVALID_ARGS));
	if (check_input(argc, argv) == -1)
		return (print_error(INVALID_ARG_FORMAT));
	init_program(argc, argv, &program);
	if (check_init(&program))
		return (print_error(INVALID_ARG_VALUE));
	init_forks(&program);
	init_philos(&program);
	printf("%ld\n", program.threads_running);
}
