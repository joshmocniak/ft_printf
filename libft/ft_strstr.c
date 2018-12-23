/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:21:32 by jmocniak          #+#    #+#             */
/*   Updated: 2018/03/14 16:59:51 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*result;
	char	*tmp_needle;
	char	*tmp_haystack;
	int		i;

	i = -1;
	if (!*needle)
		return ((char *)haystack);
	while (*(haystack + (++i)))
	{
		tmp_haystack = (char *)(haystack + i);
		tmp_needle = (char *)needle;
		if (*tmp_needle == *tmp_haystack)
		{
			result = tmp_haystack;
			while (*tmp_needle == *tmp_haystack && *tmp_needle)
			{
				tmp_needle++;
				tmp_haystack++;
			}
			if (!*tmp_needle)
				return (result);
		}
	}
	return (NULL);
}
