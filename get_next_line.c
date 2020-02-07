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
    char        *tmp;
 
    tmp = NULL;
    while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
    {
        buff[ret] = '\0';
        tmp = str;
        str = ft_strjoin(tmp, buff);
        free(tmp);
    }
    return (str);
}
 
int             get_next_line(int const fd, char **line)
{
    static char *str[3000];
    int         i;
 
    if (ft_check(fd, &str[fd], line) == -1)
        return (-1);
    str[fd] = readline(str[fd], fd);
    i = 0;
    if (str[fd][i])
    {
        while (str[fd][i] != '\n' && str[fd][i])
            i++;
        if (i == 0)
            (*line) = ft_strdup("");
        else
        {
            (*line) = ft_substr(str[fd], 0, i);
        }
        str[fd] = &str[fd][i + 1];
        return (1);
    }
    else
        (*line) = ft_strdup("");
    return (0);
}