/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:40:14 by jmocniak          #+#    #+#             */
/*   Updated: 2019/03/09 18:00:12 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		itoa_hex_str(unsigned long long num, char **str, int len, \
		t_spec *spec)
{
	char	c;
	int		i;

	c = 'a';
	if (spec->flags['X'])
		c = 'A';
	while (len > 0)
	{
		len--;
		i = num % 16;
		if (i < 10)
			(*str)[len] = i + '0';
		else
			(*str)[len] = i - 10 + c;
		num /= 16;
	}
}

static int			itoa_hex_len(unsigned long long num)
{
	int		len;

	len = 0;
	while((num /= 16))
		len++;
	return (++len);
}

void		itoa_hex(unsigned long long num, char **str, t_spec *spec)
{
	int		len;

	len = itoa_hex_len(num);
	*str = (char *)ft_memalloc(sizeof(char) * (len + 1));
	itoa_hex_str(num, str, len, spec);
}
