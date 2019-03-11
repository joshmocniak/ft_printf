/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 18:45:47 by jmocniak          #+#    #+#             */
/*   Updated: 2019/03/11 00:07:21 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			conv_f(va_list *ap, t_spec *spec)
{
	int			len;
	char		*str;

	if (spec->flags['L'])
		ldtoa(va_arg(*ap, long double), &str, spec);
	else
		dtoa(va_arg(*ap, double), &str, spec);
	width_d(&str, spec);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}
