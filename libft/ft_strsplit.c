/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:16:04 by jmocniak          #+#    #+#             */
/*   Updated: 2018/03/16 14:47:56 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numofstrings(char const *s, char c)
{
	int		numstrings;
	int		in;
	int		i;

	numstrings = 0;
	i = 0;
	in = 0;
	while (*(s + i))
	{
		if (!in && *(s + i) != c)
		{
			in = 1;
			numstrings++;
		}
		else if (in && *(s + i) == c)
			in = 0;
		i++;
	}
	return (numstrings);
}

static int	len(char *s, char c)
{
	int	i;

	i = 0;
	while (*(s + i) != c && *(s + i))
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		in;
	int		j;
	char	**str;

	i = -1;
	if (!(in = 0) && !s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_numofstrings(s, c) + 1));
	if (!(j = 0) && !str)
		return (NULL);
	while (*(s + (++i)))
	{
		if (*(s + i) == c && in)
			in = 0;
		else if (!in && *(s + i) != c && *(s + i))
		{
			*(str + j) = ft_strnew(len((char *)s + i, c) + 1);
			*(str + j) = ft_strncpy(*(str + j), s + i, len((char *)s + i, c));
			j++;
			in = 1;
		}
	}
	*(str + j) = NULL;
	return (str);
}
