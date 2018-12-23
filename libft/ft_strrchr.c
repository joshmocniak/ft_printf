/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 01:50:56 by jmocniak          #+#    #+#             */
/*   Updated: 2018/03/14 16:54:13 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;
	int		i;

	i = 0;
	result = NULL;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			result = (char *)s + i;
		i++;
	}
	if ((char)c == '\0')
		result = (char *)s + i;
	return (result);
}
