#ifndef _GET_NEXT_LINE_H_
# define _GET_NEXT_LINE_H_

#include <stdlib.h>
#include <stdio.h>

// A retirer 
#include <string.h>

# define BUFFER_SIZE = 32

size_t     ft_strlen(const char *chaine);
char    *ft_strdup(const char *chaine);
char    *ft_strrchr(const char *str, int c);
char    *ft_strjoin(const char *s1, const char *s2);


int		get_next_line(int fd, char **line);
#endif