/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:48:55 by nrossel           #+#    #+#             */
/*   Updated: 2022/12/02 14:52:02 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*--------- 1. strlen -----------*/
size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

/*--------- 3. strjoin -----------*/
char	*ft_strjoin(char *statik, char *buffer)
{
	char	*tmp_s;
	int		len;

	if (!statik || !buffer)
		return (NULL);
	len = ft_strlen(statik) + BUFFER_SIZE;
	tmp_s = malloc((len + 1) * sizeof(char));
	if (!tmp_s)
		return (NULL);
	tmp_s = ft_strncpy(tmp_s, statik, len);
	tmp_s = ft_strncpy(tmp_s + ft_strlen(statik), buffer, len);
	free(statik);
	statik = tmp_s;
	return (statik);
}

/*--------- 4. substr -----------*/
char	*ft_substr(char **statik, char *line, int index)
{
	char	*tmp_s;
	char	*tmp;
	int		len;

	len = ft_strlen(*statik) - index;
	tmp_s = malloc((ft_strlen(*statik - index) + 1) * sizeof(char));
	if (!tmp_s)
	{
		free(*statik);
		*statik = NULL;
		return (NULL);
	}
	tmp = malloc(index * sizeof(char));
	if (!tmp)
	{
		free(*statik);
		*statik = NULL;
		return (NULL);
	}
	line = tmp;
	line = ft_strncpy(line, *statik, index);
	tmp_s = ft_strncpy(tmp_s, *statik + (index + 1), len);
	free(*statik);
	*statik = tmp_s;
	return (line);
}

/*--------- str_cpy -----------*/
char	*ft_strncpy(char *dst, char *src, int size)
{
	int	i;

	i = 0;
	while (src[i] && size-- > 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
// #include <stdio.h>
// #include <stdlib.h>
// 
// int	main()
// {
	// char *s1 = "Bienvenu";
	// char *s2 = " a toi";
	// char *s3 = "Ma fois\nc'est la vie";
	// int len;
// 
	// len = 0;
	// printf("\n");
	// printf("%zu", ft_strlen(s3));
	// printf("\n");
	// printf("%s", ft_substr(&s3, 0, 7));
	// printf("\n");
	// return (0);
// }