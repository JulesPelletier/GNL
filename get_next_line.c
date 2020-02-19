/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:26:32 by julpelle          #+#    #+#             */
/*   Updated: 2020/02/19 15:08:57 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void		ft_parse(char **keep, char *buf, int *value, int fd)
{
	while (ft_s_is(*keep, '\n') == -1
			&& (*value = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[*value] = '\0';
		*keep = ft_strjoin(*keep, buf);
	}
}

int			get_next_line(int fd, char **line)
{
	static char		*keep = NULL;
	char			buf[BUFFER_SIZE + 1];
	int				value;
	char			*tmp;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0 || line == NULL)
		return (-1);
	ft_parse(&keep, buf, &value, fd);
	if (ft_s_is(keep, '\n') > -1)
	{
		*line = ft_substr(keep, 0, ft_s_is(keep, '\n'));
		tmp = ft_substr(keep, 0, ft_strlen(keep));
		keep = ft_free(keep);
		keep = ft_substr(tmp, (ft_s_is(tmp, '\n') + 1), ft_strlen(tmp));
		tmp = ft_free(tmp);
		return (1);
	}
	else
	{
		*line = ft_substr(keep, 0, ft_strlen(keep));
		keep = ft_free(keep);
	}
	return (0);
}
