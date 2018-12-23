/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:31:03 by jmocniak          #+#    #+#             */
/*   Updated: 2018/06/26 06:59:48 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordcount(const char *str)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[++i])
		if (ft_isspace(str[i]) && str[i - 1] > 040 && str[i - 1] < 0177)
			count++;
	if (str[i - 1] > 040 && str[i - 1] < 0177)
		count++;
	return (count);
}
