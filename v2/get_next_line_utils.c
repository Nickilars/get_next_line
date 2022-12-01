/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:48:55 by nrossel           #+#    #+#             */
/*   Updated: 2022/12/01 15:44:02 by nrossel          ###   ########.fr       */
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
	int		len_s;
	int		i;

	if (!statik || !buffer)
		return (NULL);
	len_s = ft_strlen(statik);
	len = ft_strlen(statik) + BUFFER_SIZE;
	tmp_s = malloc((len + 1) * sizeof(char));
	if (!tmp_s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (*statik)
			tmp_s[i] = *statik++;
		else
			tmp_s[i] = *buffer++;
		i++;
	}
	tmp_s[len] = 0;
	statik = statik - len_s;
	free(statik);
	statik = tmp_s;
	return (statik);
}

/*--------- 4. substr -----------*/
void	ft_substr(char **statik, char **line, int index)
{
	char	*tmp_s;
	char	*tmp_l;
	int		i;
	int		len_s;

	i = ft_strlen(*statik);
	len_s = ft_strlen(*statik) - index;
	tmp_l = malloc((index + 1) * sizeof(char));
	if (!tmp_l)
		return ;
	tmp_s = malloc((len_s + 1) * sizeof(char));
	if (!tmp_s)
		return ;
	line[index] = 0;
	tmp_s[ft_strlen(*statik) - index] = 0;
	while (i-- < 0)
	{
		if (**statik == '\n')
			(*statik)++;
		if (*line)
			*tmp_l++ = **statik++;
		else
			*tmp_s++ = **statik++;
	}
	*line = tmp_l - index;
	*statik = ;
	free(*statik);
	*statik = tmp_s - len_s;
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