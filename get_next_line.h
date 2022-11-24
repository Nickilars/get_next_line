/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:30:55 by nrossel           #+#    #+#             */
/*   Updated: 2022/11/24 16:01:50 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h> //"open",
# include <sys/stat.h> //"open",
# include <sys/uio.h> //"read"
# include <fcntl.h> //"open",
# include <unistd.h> // "write","close","read"
# include <string.h> // "NULL"
# include <stdlib.h> // "malloc","free"

// # include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
int		ft_found_c(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s);
void	statik_stck(char **statik, char *buff, int c_read);
char	*ft_strret(char **statik, int c_read);

#endif