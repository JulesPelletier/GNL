/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliodelavega <juliodelavega@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:52:44 by juliodelave       #+#    #+#             */
/*   Updated: 2020/02/14 11:14:00 by juliodelave      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int     main(int ac, char **av)
{
    int fd;
    int fd1;
    int fd2;
    char *line;
    int ret;

    (void)ac;
    fd1 = open(av[1], O_RDONLY);
    fd2 = open(av[2], O_RDONLY);
    fd = fd1;
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("[fd : %d] : [%d] : %s\n", fd, ret, line);
        free(line);
        fd = (fd == fd1 ? fd2 : fd1);
    }
    fd = (fd == fd1 ? fd2 : fd1);
    printf("[fd : %d] : [%d] : %s\n", fd, ret, line);
    free(line);
}