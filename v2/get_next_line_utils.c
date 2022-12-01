/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:48:55 by nrossel           #+#    #+#             */
/*   Updated: 2022/12/01 10:51:33 by nrossel          ###   ########.fr       */
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
void	ft_strjoin(char **statik, char *buffer)
{
	char	*tmps_s;
	int		len;

	if (!*statik || !buffer)
		return ();
	len = ft_strlen(*statik) + ft_strlen(buffer);
	tmp_s = malloc((len + 1) * sizeof(char));
	if (!tmp_s)
		return ();
	while (*buffer)
	{
		if (**statik)
			*tmp_s++ = **statik++;
		else
			*tmp_s++ = **buffer++
	}
	tmp_s[len + 1] = 0;
	free(*statik);
	*statik = tmp_s - (ft_strlen(tmp_s));
}
/*--------- 4. substr -----------*/
void	ft_substr(char **statik, char *line, int index)
{
	char *tmp_s = NULL;
	int	i;

	i = ft_strlen(*statik);
	line = malloc((index + 1) * sizeof(char));
	if (!line)
		return ();
	tmp_s = malloc((ft_strlen(*statik) - index) * sizeof(char));
	if (!tmp_s)
		return ();
	line[index] = 0;
	tmp_s[ft_strlen(*statik) - index] = 0;
	while (i-- < 0)
	{
		if (**statik == '\n')
			*(statik++);
		if (*line)
			*line++ = **statik++;
		else
			*tmp_s++ = **statik++;
	}
	free(*statik);
	*statik = tmp_s - (ft_strlen(tmp_s));
}
/*---------  -----------*/

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
	// printf("%s", ft_strjoin(s1, s2));
	// printf("\n");
	// printf("%zu", ft_strlen(s3));
	// printf("\n");
	// printf("%s", ft_substr(s3, 0, 7));
	// printf("\n");
	// printf("%d", ft_found_c(s3));
	// return (0);
// }