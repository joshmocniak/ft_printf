/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:01:45 by jmocniak          #+#    #+#             */
/*   Updated: 2019/03/11 00:24:36 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			d_len(long val)
{
	int	i;

	i = 0;
	while ((val /= 10))
		i++;
	return (++i);
}

long		power(int base, int exp)
{
	int		i;
	long	result;

	i = 1;
	if (exp == 0)
		return (0);
	result = base;
	while (i < exp)
	{
		result *= base;
		i++;
	}
	return (result);
}

void		itoa_snippit(char **str, int i, long val)
{
	while (i)
	{
		(*str)[--i] = val % 10 + '0';
		val /= 10;
	}
}

int			fractional(char **str, long fract, t_spec *spec)
{
	int		i;
	int		overflow;
	int		len;

	overflow = 0;
	i = spec->precision;
	len = d_len(fract);
	*str = (char *)ft_memalloc(sizeof(char) * (i + 1));
	if ((fract % 10) > 4)
		fract += 10;
	if (len < d_len(fract))
		overflow = 1;
	fract /= 10;
	itoa_snippit(str, i, fract);
	return (overflow);
}

void		ldtoa(long double num, char **str, t_spec *spec)
{
	long	whole;
	long	fract;
	int		i;
	char	*new;
	char	*combined;

	if (!(num >= 0 && (spec->ispos = 1)))
		num = -num;
	i = 0;
	if (spec->precision == -1)
		spec->precision = 6;
	whole = (int)num;
	num -= whole;
	fract = (long)(power(10, spec->precision + 1) * num);
	whole += fractional(str, fract, spec);
	if (spec->precision || spec->flags['#'])
		prefix(".", str);
	i = d_len(whole);
	new = (char *)ft_memalloc(sizeof(char) * (i + 1));
	itoa_snippit(&new, i, whole);
	combined = ft_strjoin(new, *str);
	free(*str);
	free(new);
	*str = combined;
}

void		dtoa(double num, char **str, t_spec *spec)
{
	long	whole;
	long	fract;
	int		i;
	char	*new;
	char	*combined;

	if (!(num >= 0 && (spec->ispos = 1)))
		num = -num;
	i = 0;
	if (spec->precision == -1)
		spec->precision = 6;
	whole = (long)num;
	num -= whole;
	fract = (long)(power(10, spec->precision + 1) * num);
	whole += fractional(str, fract, spec);
	if (spec->precision || spec->flags['#'])
		prefix(".", str);
	i = d_len(whole);
	new = (char *)ft_memalloc(sizeof(char) * (i + 1));
	itoa_snippit(&new, i, whole);
	combined = ft_strjoin(new, *str);
	free(*str);
	free(new);
	*str = combined;
}
