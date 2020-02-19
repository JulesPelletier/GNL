/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:54:42 by juliodelave       #+#    #+#             */
/*   Updated: 2020/02/19 15:10:46 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>

int				ft_strlen(const char *s);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_substr(char *s, int start, int len);

int				ft_s_is(char *s, char c);
char			*ft_free(char *s);
void			ft_parse(char **keep, char *buf, int *value, int fd);

int				get_next_line(int fd, char **line);

#endif
