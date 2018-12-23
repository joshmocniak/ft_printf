/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 19:04:04 by jmocniak          #+#    #+#             */
/*   Updated: 2018/03/14 22:40:30 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isnonprint(char c)
{
	int	space;

	space = 0;
	if (c == ' ' || c == '\t' || c == '\n')
		space = 1;
	if (c == '\v' || c == '\f' || c == '\r')
		space = 1;
	return (space);
}

int			ft_atoi(const char *str)
{
	int				sign;
	long long int	result;
	int				i;

	sign = 0;
	result = 0;
	i = 0;
	while (ft_isnonprint(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + ((long long int)str[i] - 48);
		i++;
	}
	if (sign)
		return (-1 * result);
	return (result);
}
