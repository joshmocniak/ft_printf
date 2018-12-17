/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoahex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:16:40 by jmocniak          #+#    #+#             */
/*   Updated: 2018/12/02 22:58:48 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		itoahex_str(unsigned long n, char *str)
{
	int		i;

	i = 0;
	if (n >= 16)
	{
		i = itoahex_str(n / 16, str);
		n %= 16;
	}
	if (n > 9)
		str[i] = n - 10 + 'a';
	else
		str[i] = n + '0';
	return (++i);
}

int		itoahex_len(unsigned long n)
{
	int	i;

	i = 0;
	while (n >= 16)
	{
		n /= 16;
		i++;
	}
	i++;
	return (i);
}

char	*itoahex(unsigned long n)
{
	char	*str;

	str = (char *)ft_memalloc(sizeof(char) * (itoahex_len(n) + 1));
	itoahex_str(n, str);
	return (str);
}
