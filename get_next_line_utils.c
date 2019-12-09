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
    int     i;
    int     j;

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

int main(int ac, char **av)
{
    int i;

    i = 1;
    while (i < ac)
    {
        printf("-------ft_strlen--------\n\n");
        printf("Mon STRLEN : %zu\n", ft_strlen(av[i]));
        printf("Leur STRLEN : %zu\n", strlen(av[i]));
        printf("-------ft_strdup--------\n\n");
        printf("Mon STRDUP : %s\n", ft_strdup(av[i]));
        printf("Leur STRDUP : %s\n", strdup(av[i]));
        printf("-------ft_strrchr-------\n\n");
        printf("Mon STRRCHR : %s\n", ft_strchr((av[i]), ' '));
        printf("Leur STRRCHR : %s\n", strchr((av[i]), ' '));
        printf("-------ft_strjoin-------\n\n");
        printf("Mon STRJOIN : %s\n", ft_strjoin(av[i - 1], av[i]));
        i++;
    }
    return (0);
}