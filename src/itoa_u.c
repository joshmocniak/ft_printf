/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 00:06:30 by jmocniak          #+#    #+#             */
/*   Updated: 2018/12/08 12:22:10 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		itoa_u_str(unsigned long long num, char **str, int len)
{
	while (len > 0)
	{
		(*str)[--len] = num % 10 + '0';
		num /= 10;
	}
}

int			itoa_u_len(unsigned long long num)
{
	int		len;

	len = 0;
	while((num /= 10))
		len++;
	return (++len);
}

void		itoa_u(unsigned long long num, char **str)
{
	int		len;

	len = itoa_u_len(num);
	*str = (char *)ft_memalloc(sizeof(char) * (len + 1));
	itoa_u_str(num, str, len);
}
