/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:20:11 by mraineri          #+#    #+#             */
/*   Updated: 2024/09/21 23:25:30 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char     buffer[BUFFER_SIZE];
    int             bits;
    char            *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
        return (NULL);
    line = "";
    if(buffer[0] != '\0')
        line = ft_strjoin(line, buffer);
    while (ft_have_breakline(line) == -1)
    {  
        bits = read(fd, buffer, BUFFER_SIZE);
        buffer[bits] = '\0';
        if(bits <= 0)
        {
            if(bits == 0)
                return (line);
            free(line);
            return (NULL);
        }
        line = ft_strjoin(line, buffer);
    }
    return (ft_strcut(line, buffer));
}


int main(void)
{
    int fd = open("TestersFile/text.txt", O_RDONLY);
    printf("%s\n", get_next_line(fd)); // AAAAABBBBB
    return (0);
}
