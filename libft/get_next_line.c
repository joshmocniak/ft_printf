/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmocniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:32:46 by jmocniak          #+#    #+#             */
/*   Updated: 2018/04/19 20:21:59 by jmocniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*strjoin_free(char *s1, char *s2)
{
	char			*tmp;

	tmp = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (tmp);
}

char				*read_file(char *store)
{
	char			*str;
	size_t			len;
	size_t			i;

	len = 0;
	while (store[len] != '\n')
		len++;
	str = ft_memalloc(len + 1);
	i = 0;
	while (i < len)
	{
		str[i] = store[i];
		i++;
	}
	return (str);
}

char				*copy_after_line(char *tmp)
{
	char *str;

	str = ft_strdup(ft_strchr(tmp, '\n') + 1);
	free(tmp);
	return (str);
}

int					get_next_line(const int fd, char **line)
{
	char			*buf;
	static char		*store[FD_MAX];
	int				res;

	if (fd < 0 || fd >= FD_MAX || BUFF_SIZE < 1 || !line)
		return (-1);
	buf = ft_memalloc(BUFF_SIZE + 1);
	if ((res = (read(fd, buf, BUFF_SIZE))) == -1)
	{
		free(buf);
		return (-1);
	}
	store[fd] = !store[fd] ? ft_memalloc(1) : store[fd];
	store[fd] = strjoin_free(store[fd], buf);
	if (!ft_strlen(store[fd]))
		return (0);
	if (ft_strchr(store[fd], '\n') && (*line = read_file(store[fd])))
		store[fd] = copy_after_line(store[fd]);
	else if (!res && ft_strlen(store[fd]) && (*line = ft_strdup(store[fd])))
		ft_strdel(&store[fd]);
	else
		return (get_next_line(fd, line));
	return (1);
}
