/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 13:44:54 by jmocniak          #+#    #+#             */
/*   Updated: 2018/03/16 00:41:15 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	while (*(s1 + i))
	{
		*(result + i) = *(s1 + i);
		i++;
	}
	while (*(s2 + j))
	{
		*(result + i + j) = *(s2 + j);
		j++;
	}
	*(result + i + j) = '\0';
	return (result);
}
