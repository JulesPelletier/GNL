#include "get_next_line.h"
 
static int      ft_check(int fd, char **str, char **line)
{
    if (fd < 0 || line == NULL ||(read(fd, *line, 0) == -1))
        return (-1);
    if (!*str)
    {
        if (!(*str = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
            return (-1);
    }
    return (0);
}
 
static char     *readline(char *str, int fd)
{
    char        buff[BUFFER_SIZE + 1];
    int         ret;
 
    while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
    {
        buff[ret] = '\0';
        str = ft_strjoin(str, buff);
    }
    return (str);
}
 
int             get_next_line(int const fd, char **line)
{
    static char *str;
    int         i;
 
    if (ft_check(fd, &str, line) == -1)
        return (-1);
    str = readline(str, fd);
    i = 0;
    if (str[i])
    {
        while (str[i] != '\n' && str[i])
            i++;
        if (i == 0)
            (*line) = ft_strdup("");
        else
        {
            (*line) = ft_substr(str, 0, i);
        }
        str = &str[i + 1];
        return (1);
    }
    else
        (*line) = ft_strdup("");
    return (0);
}