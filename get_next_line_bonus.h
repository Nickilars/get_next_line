/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:30:55 by nrossel           #+#    #+#             */
/*   Updated: 2022/12/13 11:41:33 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <sys/uio.h> //"read"
# include <unistd.h> // "write","close","read"
# include <string.h> // "NULL"
# include <stdlib.h> // "malloc","free"

# include <stdio.h> //"printf"
# include <fcntl.h> //"open"
# include <sys/types.h> //"open
# include <sys/stat.h> //"open"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

int		ft_strchr(const char *str);

char	*get_next_line(int fd);
char	*ft_strdup(const char *src);
char	*returnline(char **statik, int c_read);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_substr(char const *str, unsigned int start, size_t len);

void	ft_str2join(char **statik, char *buffer, int c_read);

#endif