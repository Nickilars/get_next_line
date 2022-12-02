/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:30:55 by nrossel           #+#    #+#             */
/*   Updated: 2022/12/02 13:51:51 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/uio.h> //"read"
# include <unistd.h> // "write","close","read"
# include <string.h> // "NULL"
# include <stdlib.h> // "malloc","free"

# include <stdio.h> //"printf"
# include <fcntl.h> //"open"
# include <sys/types.h> //"open
# include <sys/stat.h> //"open"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *statik, char *buffer);
char	*ft_strncpy(char *dst, char *src, int size);
char	*ft_substr(char **statik, char *line, int index);

void	statik_check(char **statik, char *buffer);
void	ft_strdup(char **statik, char *buffer);

int		ft_isline(char *statik, int *c_read);

size_t	ft_strlen(char *s);

#endif