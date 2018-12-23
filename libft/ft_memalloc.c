/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 15:21:48 by jmocniak          #+#    #+#             */
/*   Updated: 2018/03/14 16:38:18 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*result;

	result = (char *)malloc(size);
	if (!result)
		return (NULL);
	while (size)
	{
		*(result + size - 1) = 0;
		size--;
	}
	return ((void *)result);
}
