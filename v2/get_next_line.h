/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:30:55 by nrossel           #+#    #+#             */
/*   Updated: 2022/12/01 10:51:34 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/uio.h> //"read"
# include <unistd.h> // "write","close","read"
# include <string.h> // "NULL"
# include <stdlib.h> // "malloc","free"

//# include <stdio.h>"printf"
//# include <fcntl.h> //"open"
//# include <sys/types.h> //"open
//# include <sys/stat.h> //"open"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);

void	ft_strdup(char **statik, char *buffer);
void	ft_strjoin(char **statik, char *buffer);
void	ft_substr(char **statik, char *line, int index);

int		ft_isline(char *statik, int *c_read);

size_t	ft_strlen(char *s);

#endif