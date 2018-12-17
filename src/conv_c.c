/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:33:54 by jmocniak          #+#    #+#             */
/*   Updated: 2018/11/30 15:50:05 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conv_c(va_list *ap, t_spec *spec)
{
	char	*str;
	int		len;

	str = (char *)ft_memalloc(sizeof(char) * 2);
	str[0] = va_arg(*ap, int);
	width_s(&str, spec);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}
