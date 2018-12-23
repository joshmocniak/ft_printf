/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:25:39 by jmocniak          #+#    #+#             */
/*   Updated: 2018/03/14 16:36:59 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_isnegative(int *n, int *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

char		*ft_itoa(int n)
{
	int		tmpn;
	int		len;
	int		neg;
	char	*s;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmpn = n;
	len = 2;
	neg = 0;
	ft_isnegative(&n, &neg);
	while (tmpn /= 10)
		len++;
	len += neg;
	if (!(s = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	*(s + (--len)) = '\0';
	while (len--)
	{
		*(s + len) = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		*s = '-';
	return (s);
}
