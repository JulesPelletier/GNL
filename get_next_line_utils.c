#include "get_next_line.h"
#include <stdlib.h>

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

    len = (int)ft_strlen(chaine);
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

char    *ft_strjoin(const char *s1, const char *s2)
{
    char    *chaine;
    size_t  len_s1;
    size_t  len_s2;
    size_t     i;
    size_t     j;

    len_s1 = ft_strlen(s1);
    len_s2 = ft_strlen(s2);
    i = 0;
    j = 0;
    if (!(chaine = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
        return (NULL);
    while (i < len_s1)
    {
        chaine[i] = s1[i];
        i++;
    }
    while (i < len_s1 + len_s2)
    {
        chaine[i] = s2[j];
        j++;
        i++;
    }
    chaine[i] = '\0';
    return (chaine);
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