/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:42:51 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/21 17:25:55 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include <fcntl.h>

long	ft_atol(char *str)
{
	long	nbr;

	nbr = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == ADDITION_ASCII)
		str++;
	while (ft_isdigit(*str))
		nbr = nbr * 10 + (*str++ - 48);
	if (nbr > INT_MAX)
		return (-1);
	return (nbr);
}
