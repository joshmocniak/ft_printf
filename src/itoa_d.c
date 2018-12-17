/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 21:01:35 by jmocniak          #+#    #+#             */
/*   Updated: 2018/12/08 12:20:46 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		itoa_str(long long num, char **str, int len)
{
	while (len > 0)
	{
		(*str)[--len] = num % 10 + '0';
		num /= 10;
	}
}

int			itoa_len(long long num)
{
	int		len;

	len = 0;
	while((num /= 10))
		len++;
	return (++len);
}

void		itoa_d(long long num, char **str, t_spec *spec)
{
	int		len;

	if (num >= 0)
		spec->ispos = 1;
	else	
		num = -num;
	len = itoa_len(num);
	*str = (char *)ft_memalloc(sizeof(char) * (len + 1));
	itoa_str(num, str, len);
}
