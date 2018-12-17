/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:17:50 by jmocniak          #+#    #+#             */
/*   Updated: 2018/12/08 12:22:38 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			conv_u(va_list *ap, t_spec *spec)
{
	int			len;
	char		*str;
	long long	num;

	spec->isunsigned = 1;
	num = lenmod_unsigned(ap, spec);
	itoa_u(num, &str);
	precision_d(&str, spec);
	width_d(&str, spec);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);	
	return (len);
}
