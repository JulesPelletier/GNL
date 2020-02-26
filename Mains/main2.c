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
    char *line;
    int ret;

    (void)ac;
    fd = open(av[1], O_RDONLY);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("[fd : %d] : [%d] : %s\n", fd, ret, line);
        free(line);
    }
    printf("[fd : %d] : [%d] : %s\n", fd, ret, line);
    free(line);
    system("leaks a.out");
}
