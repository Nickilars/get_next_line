/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:30:55 by nrossel           #+#    #+#             */
/*   Updated: 2022/11/21 15:00:57 by nrossel          ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		ft_found_c(char *s, int *index);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s);
int		read_n_stck(int fd, char **tmp);
void	ft_n_found(char **line, char **tmp, int *index);

#endif