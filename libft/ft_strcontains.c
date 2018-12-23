/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcontains.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:13:13 by jmocniak          #+#    #+#             */
/*   Updated: 2018/03/14 16:19:04 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcontains(char *str, char *query)
{
	int	len;

	len = ft_strlen(query);
	while (*str)
	{
		if (ft_strnequ(str, query, len))
			return (1);
		str++;
	}
	return (0);
}
