/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 21:27:10 by jmocniak          #+#    #+#             */
/*   Updated: 2018/03/15 18:34:21 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		difference;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		difference = *((unsigned char *)s1 + i) - *((unsigned char *)s2 + i);
		if (difference)
			break ;
		i++;
	}
	return (difference);
}
