/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 01:09:33 by jmocniak          #+#    #+#             */
/*   Updated: 2019/03/11 01:10:47 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#includes "ft_printf.h"

int		get_width_precision(const char * restrict * format, int *wdt, int *prc)
{
	int	result;
	int	more;

	result = 0;
	more = 0;
	while (ft_isdigit(**format))
	{
		result = result * 10 + (**format - '0');
		(*format)++;
	}
	if (result && (*wdt = result))
		more = 1;
	if (**format == '.')
	{
		(*format)++;
		result = 0;
		while (ft_isdigit(**format))
		{
			result = result * 10 + (**format - '0');
			(*format)++;
		}
		*prc = result;
		more = 1;
	}
	return (more);
}

char	is_flag(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+')
		return (1);
	return (0);
}

int		get_flags(const char * restrict * format, char *flags)
{
	int		more;

	more = 0;
	while (is_flag(**format))
	{
		more = 1;
		flags[(int)*(*format)++] = 1;
	}
	return (more);
}

int		convert_next_arg(const char * restrict * format, va_list *ap,
		int (*dispatch[])(), t_spec *spec)
{
	char	conv;
	int		more;

	if (**format == '%')
	{
		ft_putchar((*(*format)++));
		return (1);
	}
	more = 1;
	while (more)
	{
		more = 0;
		more += get_flags(format, spec->flags);
		more += get_width_precision(format, &spec->width, &spec->precision);	
		more += get_len_modifier(format, spec->flags);
	}
	if ((conv = get_conv_spec(format, spec->flags)) == 0)
	{
		if (**format)
			return (conv_single(spec, *(*format)++));
		return (0);
	}
	if (spec->flags[(int)'j'] && spec->flags[(int)'x'])
		return (j_conv_x(ap, spec));
	return (dispatch[(int)conv](ap, spec));
}
