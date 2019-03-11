/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenmod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 22:01:21 by jmocniak          #+#    #+#             */
/*   Updated: 2019/03/11 00:38:53 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long			lenmod(va_list *ap, t_spec *spec)
{
	long long			num;

	if (spec->flags['l'] == 2)
		num = va_arg(*ap, long long);
	else if (spec->flags['l'] == 1)
		num = va_arg(*ap, long);
	else if (spec->flags['h'] == 2)
		num = (signed char)va_arg(*ap, int);
	else if (spec->flags['h'] == 1)
		num = (short)va_arg(*ap, int);
	else
		num = va_arg(*ap, int);
	return (num);
}

unsigned long long	lenmod_unsigned(va_list *ap, t_spec *spec)
{
	unsigned long long	num;

	if (spec->flags['l'] == 2)
		num = va_arg(*ap, unsigned long long);
	else if (spec->flags['l'] == 1)
		num = va_arg(*ap, unsigned long);
	else if (spec->flags['h'] == 2)
		num = (unsigned char)va_arg(*ap, unsigned int);
	else if (spec->flags['h'] == 1)
		num = (unsigned short)va_arg(*ap, unsigned int);
	else
		num = va_arg(*ap, unsigned int);
	return (num);
}

uintmax_t			j_lenmod(va_list *ap, t_spec *spec)
{
	uintmax_t	num;

	(void)*spec;
	num = va_arg(*ap, intmax_t);
	return (num);
}
