/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 16:44:21 by jmocniak          #+#    #+#             */
/*   Updated: 2018/03/15 23:29:26 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!need[j])
		return ((char *)hay);
	while (hay[i] != '\0' && i < len)
	{
		j = 0;
		while (hay[i + j] && (i + j) < len && hay[i + j] == need[j])
			j++;
		if (need[j] == '\0')
			return ((char *)&hay[i]);
		i++;
	}
	return (NULL);
}
