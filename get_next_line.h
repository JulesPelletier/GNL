/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliodelavega <juliodelavega@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:54:42 by juliodelave       #+#    #+#             */
/*   Updated: 2020/02/14 15:10:14 by juliodelave      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H_
# define _GET_NEXT_LINE_H_

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

size_t          ft_strlen(const char *chaine);
char            *ft_strdup(const char *chaine);
char            *ft_strchr(const char *str, int c);
char            *ft_strjoin(const char *s1, const char *s2);
char            *ft_substr(char const *s, unsigned int start, size_t len);

int             get_next_line(int fd, char **line);

#endif
