/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:10:15 by jmocniak          #+#    #+#             */
/*   Updated: 2019/03/08 18:18:09 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		prefix(char *pre, char **str)
{
	char	*new;

	new = ft_strjoin(pre, *str);
	free(*str);
	*str = new;
}

void		suffix(char **str, char *post)
{
	char	*new;

	new = ft_strjoin(*str, post);
	free(*str);
	*str = new;
}

void		prefix_octal(char **str, t_spec *spec)
{
	if (spec->flags['o'] && spec->flags['#'])
		prefix("0", str);
}

void		precision_d(char **str, t_spec *spec)
{
	char	*new;
	int		len;
	int		pad_len;
	int		i;
	char	*padding;

	len = ft_strlen(*str);
	if (spec->precision != -1 && (pad_len = spec->precision - len) > 0)
	{
		padding = (char *)ft_memalloc(sizeof(char) * (pad_len + 1));
		i = 0;
		while (i < pad_len)
			padding[i++] = '0';
		new = ft_strjoin(padding, *str);
		free(*str);
		free(padding);
		*str = new;
	}
	//
	// FIX RIGHT HERE
	//
	else if (spec->precision == 0 && spec->iszero)
	{
		free(*str);
		*str = (char *)ft_memalloc(sizeof(char) * 1);
	}
	prefix_octal(str, spec);
}

void		prefix_sign(char **str, t_spec *spec)
{
	if (spec->isunsigned)
	{
		if (spec->flags['#'] && spec->flags['x'] && !(spec->iszero))
			prefix("0x", str);
		if (spec->flags['#'] && spec->flags['X'] && !(spec->iszero))
			prefix("0X", str);
		return ;
	}
	if (!spec->ispos)
		prefix("-", str);
	else if (spec->flags['+'])
		prefix("+", str);
	else if (spec->flags[' '])
		prefix(" ", str);
}

void		width_d(char **str, t_spec *spec)
{
	int		pad_len;
	int		len;
	char	c;
	int		i;
	char	*new;
	char	*padding;

	len = ft_strlen(*str);
	if (spec->width != -1 && (pad_len = spec->width - len) > 0)
	{
		if (!spec->isunsigned && (!spec->ispos || spec->flags[' '] || \
					spec->flags['+']))
			pad_len--;
		else if (spec->flags['#'] && (spec->flags['x'] || spec->flags['X']))
			pad_len -= 2;
		padding = (char *)ft_memalloc(sizeof(char) * (pad_len + 1));
		c = ' ';
		if ((spec->precision == -1 || spec->flags['f']) && !spec->flags['-'] \
				&& spec->flags['0'])
			c = '0';
		i = 0;
		while (i < pad_len)
			padding[i++] = c;
		if (spec->flags['-'])
			new = ft_strjoin(*str, padding);
		else if (c == '0')
			new = ft_strjoin(padding, *str);
		else
		{
			prefix_sign(str, spec);
			new = ft_strjoin(padding, *str);
		}
		free(*str);
		free(padding);
		*str = new;
		if (spec->flags['-'] || c == '0')
			prefix_sign(str, spec);
	}
	else
		prefix_sign(str, spec);
}

int			conv_d(va_list *ap, t_spec *spec)
{
	int			len;
	char		*str;
	long long	num;
	
	num = lenmod(ap, spec);
	if (num == 0)
		spec->iszero = 1;
	itoa_d(num, &str, spec);
	precision_d(&str, spec);
	width_d(&str, spec);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);	
	return (len);
}
