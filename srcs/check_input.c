/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:48:15 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/09 08:14:06 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_isspace(char c)
{
	if ((c >= HORIZONTAL_TAB && c <= CARRIAGE_RETURN) || c == SPACE_ASCII)
		return (1);
	return (0);
}

int	ft_isdigit(char c)
{
	if (c >= ZERO_ASCII && c <= NINE_ASCII)
		return (1);
	return (0);
}

static int	is_valid_format(char *str)
{
	int	str_length;

	str_length = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == ADDITION_ASCII || *str == SUBTRACTION_ASCII)
	{
		if (*str == SUBTRACTION_ASCII)
			return (-1);
		str++;
	}
	while (ft_isdigit(*str))
	{
		str_length++;
		str++;
	}
	while (ft_isspace(*str))
		str++;
	if (*str || str_length > 10 || str_length == 0)
		return (-1);
	return (0);
}

int	check_input(int argc, char *argv[])
{
	int	row;

	row = 0;
	while (++row < argc)
	{
		if (is_valid_format(argv[row]))
			return (-1);
	}
	return (0);
}
