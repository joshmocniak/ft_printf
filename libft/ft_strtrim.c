/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:12:58 by jmocniak          #+#    #+#             */
/*   Updated: 2018/03/16 01:29:46 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*result;

	i = 0;
	j = 0;
	k = 0;
	if (!s)
		return (NULL);
	while (s[i] && ft_isspace(s[i]))
		i++;
	if (!*(s + i))
		return (ft_memalloc(1));
	j = ft_strlen(s) - 1;
	while (ft_isspace(s[j]))
		j--;
	result = (char *)malloc(j - i + 2);
	if (!result)
		return (NULL);
	while (i < j + 1)
		*(result + k++) = *(s + i++);
	*(result + k) = '\0';
	return (result);
}
