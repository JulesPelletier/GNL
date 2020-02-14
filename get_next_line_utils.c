/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliodelavega <juliodelavega@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:54:29 by juliodelave       #+#    #+#             */
/*   Updated: 2020/02/14 15:07:54 by juliodelave      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t     ft_strlen(const char *chaine)
{
    size_t i;

    i = 0;
    while (chaine[i])
        i++;
    return (i);
}


char    *ft_strdup(const char *chaine)
{
    int     len;
    int     i;
    char    *dup;

    len = ft_strlen(chaine);
    i = 0;
    if (!(dup = (char *)malloc(sizeof(char) * (len + 1))))
        return (NULL);
    while (i < len)
    {
        dup[i] = chaine[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

char    *ft_strchr(const char *str, int c)
{
    int i;

    i = 0;
    while (str[i] != (char)c)
    {
        if (str[i] == '\0' && (char)c != '\0')
            return (0);
        i++;
    }
    return (char *)(&str[i]);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		str = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len1] = s2[i];
			len1++;
		}
		str[len1] = '\0';
		return (str);
	}
	return (NULL);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		cpy;
	size_t	lalen;

	if (s == NULL || start < 0)
		return (NULL);
	lalen = ft_strlen((char *)s);
	if (start >= lalen)
		len = 0;
	else
		len = lalen - start < len ? lalen - start : len;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == 0)
		return (NULL);
	cpy = 0;
	while (len)
	{
		res[cpy] = s[start];
		cpy++;
		start++;
		len--;
	}
	res[cpy] = '\0';
	return (res);
}