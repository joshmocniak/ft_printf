/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:21:44 by jmocniak          #+#    #+#             */
/*   Updated: 2018/11/30 15:49:58 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precision_s(char **str, t_spec *spec)
{
	char	*new;
	int		i;

	if (spec->precision == -1)
		return;
	if (ft_strlen(*str) > (size_t)spec->precision)
	{
		new = (char *)ft_memalloc(spec->precision + 1);
		i = -1;
		while (++i < spec->precision)
			new[i] = (*str)[i];
		free(*str);
		*str = new;	
	}
}

char	*width_s_2(int pad_len, char *padding, char c)
{
	int		i;

	i = -1;
	while (++i < pad_len)
		padding[i] = c;
	return (padding);
}

void	width_s(char **str, t_spec *spec)
{
	int		len;
	char	*padding;
	char	*new;
	int		pad_len;
	
	if (spec->width == -1 || spec->width <= (len = ft_strlen(*str)))
		return ;
	pad_len = spec->width - len;
	padding = (char *)ft_memalloc(pad_len + 1);
	if (spec->flags['-'])
		new = ft_strjoin(*str, width_s_2(pad_len, padding, ' '));
	else if (spec->flags['0'])
		new = ft_strjoin(width_s_2(pad_len, padding, '0'), *str);
	else
		new = ft_strjoin(width_s_2(pad_len, padding, ' '), *str);
	free(padding);
	free(*str);
	*str = new;
}

int		conv_s(va_list *ap, t_spec *spec)
{
	char	*str;
	int		len;

	str = ft_strdup(va_arg(*ap, char *));
	precision_s(&str, spec);
	width_s(&str, spec);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}
