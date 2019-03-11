/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix_suffix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 23:59:11 by jmocniak          #+#    #+#             */
/*   Updated: 2019/03/11 00:00:52 by jmocniak         ###   ########.fr       */
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
	if (spec->flags['o'] && spec->flags['#'] && str[0][0] != '0')
		prefix("0", str);
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
