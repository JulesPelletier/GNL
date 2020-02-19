/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:26:45 by julpelle          #+#    #+#             */
/*   Updated: 2020/02/19 15:14:56 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strlen(const char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char		*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*new;

	i = 0;
	if (!s)
		s = "";
	if (ft_strlen(s) < start)
		len = 0;
	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len && s[start])
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}

char		*ft_strjoin(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*new;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_substr("", 0, 0);
	if (!(new = (char *)malloc(sizeof(char)
		* (ft_strlen(s1) + ft_strlen(s2) + 1))))
	{
		s1 = ft_free(s1);
		return (NULL);
	}
	while (s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new[j++] = s2[i++];
	new[j] = '\0';
	s1 = ft_free(s1);
	return (new);
}
