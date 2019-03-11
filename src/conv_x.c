/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:39:12 by jmocniak          #+#    #+#             */
/*   Updated: 2019/03/11 00:23:01 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			conv_x(va_list *ap, t_spec *spec)
{
	int			len;
	char		*str;
	long long	num;

	spec->isunsigned = 1;
	num = lenmod_unsigned(ap, spec);
	if (num == 0)
		spec->iszero = 1;
	itoa_hex(num, &str, spec);
	precision_d(&str, spec);
	width_d(&str, spec);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}
