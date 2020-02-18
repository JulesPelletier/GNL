/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:37:23 by juliodelave       #+#    #+#             */
/*   Updated: 2020/02/18 14:56:52 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/uio.h>

int			ft_s_is(char *s, char c)
{
	int		i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char		*ft_free(char *s)
{
	free(s);
	s = NULL;
	return (s);
}

void		ft_parse(char **str, char *buf, int *ret, int fd)
{
	while (ft_s_is(*str, '\n') == -1
			&& (*ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[*ret] = '\0';
		*str = ft_strjoin(*str, buf);
	}
}

int			get_next_line(int fd, char **line)
{
	static char		*str = NULL;
	char			buf[BUFFER_SIZE + 1];
	int				ret;
	char			*tmp;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0 || line == NULL)
		return (-1);
	ft_parse(&str, buf, &ret, fd);
	if (ft_s_is(str, '\n') > -1)
	{
		*line = ft_substr(str, 0, ft_s_is(str, '\n'));
		tmp = ft_substr(str, 0, ft_strlen(str));
		str = ft_substr(tmp, (ft_s_is(str, '\n') + 1), ft_strlen(str));
		tmp = ft_free(tmp);
		return (1);
	}
	else
	{
		*line = ft_substr(str, 0, ft_strlen(str));
		str = ft_free(str);
	}
	return (0);
}