/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:39:12 by jmocniak          #+#    #+#             */
/*   Updated: 2019/03/06 00:24:16 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int			j_conv_x(va_list *ap, t_spec *spec)
{
	int			len;
	char		*str;
	uintmax_t	num;

	spec->isunsigned = 1;
	num = j_lenmod(ap, spec);
	printf("%jx\n", num);
	j_itoa_hex(num, &str, spec);
	printf("%s\n", str);
	precision_d(&str, spec);
	width_d(&str, spec);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);	
	return (len);
}
