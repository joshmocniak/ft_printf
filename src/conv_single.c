/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_single.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 02:14:19 by jmocniak          #+#    #+#             */
/*   Updated: 2019/03/11 00:21:25 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conv_single(t_spec *spec, char c)
{
	char	*str;
	int		len;

	str = (char *)ft_memalloc(sizeof(char) * 2);
	str[0] = c;
	width_s(&str, spec);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}
