#ifndef _GET_NEXT_LINE_H_
# define _GET_NEXT_LINE_H_

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

// A retirer 
#include <string.h>

# define MAX_FD = (int)3000

size_t  ft_strlen(const char *chaine);
char    *ft_strdup(const char *chaine);
char    *ft_strchr(const char *str, int c);
char    *ft_strjoin(const char *s1, const char *s2);
char    *ft_substr(char const *s, unsigned int start, size_t len);

int     get_next_line(int fd, char **line);

#endif