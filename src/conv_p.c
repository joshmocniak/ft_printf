/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:08:58 by jmocniak          #+#    #+#             */
/*   Updated: 2019/03/11 01:43:11 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

void	precision_p(char **str, t_spec *spec)
{
	int		i;
	int		len;
	int		pad_len;
	char	*padding;
	char	*new;

	len = ft_strlen(*str);
	if (spec->precision == -1 || spec->precision < len)
		return ;
	pad_len = spec->precision - len;
	padding = (char *)ft_memalloc(sizeof(char) * (pad_len + 1));
	i = -1;
	while (++i < pad_len)
		padding[i] = '0';
	new = ft_strjoin(padding, *str);
	free(padding);
	free(*str);
	*str = new;
}

void	prefix_0x(char **str)
{
	char	*new;

	new = ft_strjoin("0x", *str);
	free(*str);
	*str = new;
}

void	width_p_2(char **str, t_width_d v)
{
	prefix_0x(str);
	v.new = ft_strjoin(width_s_2(v.pad_len, v.padding, ' '), *str);
	free(v.padding);
	free(*str);
	*str = v.new;
}

void	width_p(char **str, t_spec *spec)
{
	t_width_d	v;

	if (spec->width == -1 || spec->width <= (v.len = ft_strlen(*str)) + 2)
	{
		prefix_0x(str);
		return ;
	}
	v.pad_len = spec->width - (v.len + 2);
	v.padding = (char *)ft_memalloc(v.pad_len + 1);
	if (spec->flags['-'])
		v.new = ft_strjoin(*str, width_s_2(v.pad_len, v.padding, ' '));
	else if (spec->flags['0'] && spec->precision == -1)
		v.new = ft_strjoin(width_s_2(v.pad_len, v.padding, '0'), *str);
	else
	{
		width_p_2(str, v);
		return ;
	}
	prefix_0x(&v.new);
	free(v.padding);
	free(*str);
	*str = v.new;
}

int		conv_p(va_list *ap, t_spec *spec)
{
	char	*str;
	int		len;
	void	*vp;

	vp = va_arg(*ap, void *);
	itoa_hex((unsigned long)vp, &str, spec);
	precision_p(&str, spec);
	width_p(&str, spec);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}
