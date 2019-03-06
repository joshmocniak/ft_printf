/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:33:54 by jmocniak          #+#    #+#             */
/*   Updated: 2019/03/06 14:32:57 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conv_c(va_list *ap, t_spec *spec)
{
	char	*str;
	int		len;

	str = (char *)ft_memalloc(sizeof(char) * 2);
	str[0] = va_arg(*ap, int);
	if (str[0] == 0)
	{
		spec->isnull = 1;
		spec->width = spec->width != -1 ? spec->width - 1 : -1;
	}
	width_s(&str, spec);
	len = ft_strlen(str) + spec->isnull;
	ft_putstr(str);
	free(str);
	if (spec->isnull)
		ft_putchar(0);
	return (len);
}
