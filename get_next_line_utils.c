/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:58:45 by mraineri          #+#    #+#             */
/*   Updated: 2024/09/17 21:46:14 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_have_breakline(char *buffer)
{
	int	i;

	i = 0;
	if(!buffer)
		return (-1);
	while (buffer[i] != '\0')
    {
		if (buffer[i] == '\n')
			return (i);
		i++;
    }
	return (-1);
}

int ft_strlen(char *str)
{
	int	i; 

	i = 0;
	if(!str)
		return (-1);
	while(str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*str;

	if(!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	i = 0;
	while(*s1)
		str[i++] = *s1++;
	while(*s2)
		str[i++] = *s2++;
	return(str);
}
