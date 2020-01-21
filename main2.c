#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

#define NRM  "\x1B[0m"
#define RED  "\x1B[31m"
#define GRE  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"


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

int main(int ac, char **av)
{
    int     fd1;
    char    **s;
    int     ret;

    fd1 = 0;
    s = NULL;
    ret = 0;
    if (ac == 2)
	{
		fd1 = open(av[1], O_RDONLY);
        printf("READ resultat : %d\n", ft_read_files(fd1, "test.txt", ret));
		while ((ret1 = get_next_line(fd1, &str)) > 0)
		{
			printf(MAG"line %d "GRE"file 1 : %s\n", i, str);
			free(str);
		}
		i++;
		close(fd1);
	}
}