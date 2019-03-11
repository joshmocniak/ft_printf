/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 19:47:10 by jmocniak          #+#    #+#             */
/*   Updated: 2019/03/09 23:40:21 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	is_conv_spec(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || \
			c == 'i' || c == 'o' || c == 'u' || \
			c == 'x' || c == 'X' || c == 'f')
		return (1);
	return (0);
}

char	get_conv_spec(const char * restrict * format, char *flags)
{
	if (is_conv_spec(**format))
	{
		flags[(int)**format] = 1;
		return (*(*format)++);
	}
	return (0);
}

char	is_len_mod(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 't' || c == 'z')
		return (1);
	return (0);
}

int		get_len_modifier(const char * restrict * format, char *flags)
{
	int		more;

	more = 0;
	if (is_len_mod(**format))
	{
		more = 1;
		if (**format == *((*format) + 1))
		{
			flags[(int)**format] = 2;
			*format += 2;
		}
		else
			flags[(int)*((*format)++)] = 1;
	}
	while (is_len_mod(**format))
	{
		//skips more than one length modifier
		(*format)++;
	}
	return (more);
}

int		get_width_precision(const char * restrict * format, int *wdt, int *prc)
{
	int	result;
	int	more;

	result = 0;
	more = 0;
//	if (ft_isdigit(**format))
//	{
		while (ft_isdigit(**format))
		{
			result = result * 10 + (**format - '0');
			(*format)++;
		}
		if (result)
		{
			*wdt = result;
			more = 1;
		}
//	}
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

void	init_dispatch(int (*dispatch[])())
{
	dispatch['s'] = conv_s;
	dispatch['c'] = conv_c;
	dispatch['p'] = conv_p;
	dispatch['d'] = conv_d;
	dispatch['i'] = conv_d;
	dispatch['u'] = conv_u;
	dispatch['o'] = conv_o;	
	dispatch['x'] = conv_x;
	dispatch['X'] = conv_x;
	dispatch['f'] = conv_f;
}

void	init_spec(t_spec *spec)
{
	spec->width = -1;
	spec->precision = -1;
	spec->isnull = 0;
	spec->iszero = 0;
	spec->ispos = 0;
	spec->isunsigned = 0;
	ft_bzero(spec->flags, 128);
}

int		helper(va_list *ap, const char * restrict format)
{
	int		num;
	int		(*dispatch[128])(va_list *ap, t_spec *spec);
	int		num_printed;
	t_spec	spec;

	spec.flags = (char *)ft_memalloc(sizeof(char) * 128);
	init_dispatch(dispatch);
	num = 0;
	while(*format)
	{
		if (*format == '%')
		{
			format++;
			init_spec(&spec);
			num_printed = convert_next_arg(&format, ap, dispatch, &spec);
			//if (num_printed == 0)
			//	return (-1);
			num += num_printed;
		}
		else
		{
			ft_putchar(*format);
			num++;
			format++;
		}	

	}

	return (num);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		num_chars_printed;

	va_start(ap, format);
	num_chars_printed = helper(&ap, format);
	va_end(ap);
	return(num_chars_printed);
}
