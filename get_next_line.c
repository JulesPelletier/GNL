#include "get_next_line.h"

int			ft_read_files(int fd, char **s, int ret)
{
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;

	while ((ret = read(fd, &buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!(tmp = ft_strjoin(s[fd], buff)))
			return (-1);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (ret);
}


int		get_next_line(int fd, char **line)
{
    int     ret;
    int     len;

    len = 0;
    ret = 1;
    if (line == NULL || fd < 0 || BUFFER_SIZE <= 0)
        return (-1)
}
