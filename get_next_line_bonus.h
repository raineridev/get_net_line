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

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

// Includes

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// Define

// # define BUFFER_SIZE 10
# define OPEN_MAX 1024

// Functions: 

/// Int Retun's

int	    ft_have_breakline(char *buffer);
int	    ft_strlen(char *str);

/// Char Retun's
char    *get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2, size_t len_s1, size_t len_s2);
char    *ft_strcut(char *line, char *buffer);
#endif





