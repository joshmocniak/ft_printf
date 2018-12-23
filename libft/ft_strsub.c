/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 03:26:11 by jmocniak          #+#    #+#             */
/*   Updated: 2018/03/16 00:40:38 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	i = (size_t)start;
	j = 0;
	if (!s)
		return (NULL);
	if ((size_t)start + len > ft_strlen(s) + 1)
		return (NULL);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (i < (size_t)start + len)
	{
		*(sub + j) = *(s + i);
		i++;
		j++;
	}
	*(sub + j) = '\0';
	return (sub);
}
