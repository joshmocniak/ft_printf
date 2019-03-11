/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 01:06:47 by jmocniak          #+#    #+#             */
/*   Updated: 2019/03/11 01:07:07 by jmocniak         ###   ########.fr       */
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
		(*format)++;
	return (more);
}
