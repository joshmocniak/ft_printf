/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:39:12 by jmocniak          #+#    #+#             */
/*   Updated: 2019/03/06 00:28:50 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			j_conv_x(va_list *ap, t_spec *spec)
{
	int			len;
	char		*str;
	uintmax_t	num;

	spec->isunsigned = 1;
	num = j_lenmod(ap, spec);
	j_itoa_hex(num, &str, spec);
	precision_d(&str, spec);
	width_d(&str, spec);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);	
	return (len);
}
