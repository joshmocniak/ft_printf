/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 23:29:55 by jmocniak          #+#    #+#             */
/*   Updated: 2018/03/14 16:53:15 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	int		reached_end;

	i = 0;
	reached_end = 0;
	while (i < len)
	{
		if (!reached_end)
		{
			if (*(src + i) == '\0')
				reached_end = 1;
			*(dst + i) = *(src + i);
		}
		else
			*(dst + i) = '\0';
		i++;
	}
	return (dst);
}
