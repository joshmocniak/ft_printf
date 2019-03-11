/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_octal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 23:54:59 by jmocniak          #+#    #+#             */
/*   Updated: 2019/03/11 00:37:53 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		itoa_oct_str(unsigned long long num, char **str, int len)
{
	while (len > 0)
	{
		(*str)[--len] = num % 8 + '0';
		num /= 8;
	}
}

int			itoa_oct_len(unsigned long long num)
{
	int		len;

	len = 0;
	while ((num /= 8))
		len++;
	return (++len);
}

void		itoa_octal(unsigned long long num, char **str)
{
	int		len;

	len = itoa_oct_len(num);
	*str = (char *)ft_memalloc(sizeof(char) * (len + 1));
	itoa_oct_str(num, str, len);
}
