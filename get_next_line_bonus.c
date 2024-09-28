/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:20:11 by mraineri          #+#    #+#             */
/*   Updated: 2024/09/26 22:43:19 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *get_next_line(int fd)
{
    static char     buffer[OPEN_MAX][BUFFER_SIZE + 1];
    int             bits;
    char            *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
        return (NULL);
    line = NULL;
    if(buffer[fd][0] != '\0')
        line = ft_strjoin(line, buffer[fd], ft_strlen(line), ft_strlen(buffer[fd]));
    while (ft_have_breakline(line) == -1)
    {  
        bits = read(fd, buffer[fd], BUFFER_SIZE);
        buffer[fd][bits] = '\0';
        if(bits == 0)
            return (line);
        if(bits < 0)
            return(free(line), NULL);
        line = ft_strjoin(line, buffer[fd], ft_strlen(line), ft_strlen(buffer[fd]));
    }
    return (ft_strcut(line, buffer[fd]));
}

