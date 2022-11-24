/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:40:15 by nrossel           #+#    #+#             */
/*   Updated: 2022/11/24 15:45:53 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*---------------- strdup ------------------*/

char	*ft_strdup(char *s)
{
	char	*new_s;
	int		len;

	len = ft_strlen(s);
	if (!s || !*s)
		return (NULL);
	new_s = ft_calloc((len + 1), sizeof(char));
	if (!new_s)
		return (NULL);
	while (*s)
	{
		*new_s++ = *s++;
	}
	return (new_s - len);
}

/*---------------- statik_stockage ------------------*/
void	statik_stck(char **statik, char *buff, int c_read)
{
	char	*tmp;

	if (!buff)
		return ;
	if (!*statik)
		*statik = ft_substr(buff, 0, c_read);
	else
	{
		buff[c_read] = 0;
		tmp = ft_strjoin(*statik, buff);
		free(*statik);
		*statik = tmp;
	}
}

/*---------------- str_returned ------------------*/
char	*ft_strret(char **statik, int c_read)
{
	char	*ret;
	char	*tmp;
	int		len;

	if (!**statik)
		free(*statik);
	if (!**statik)
		return (NULL);
	len = ft_found_c(*statik) + 1;
	if (len == 0)
		len = ft_strlen(*statik);
	ret = ft_substr(*statik, 0, len);
	tmp = ft_substr(*statik, len, ft_strlen(*statik) - len);
	free(*statik);
	if (c_read == 0)
	{
		free(tmp);
		*statik = NULL;
		return (NULL);
	}
	*statik = tmp;
	return (ret);
}
/*---------------- get_next_line ------------------*/

char	*get_next_line(int fd)
{
	static char	*statik;
	char		*line;
	char		buff[BUFFER_SIZE + 1];
	int			i_sep;
	int			c_read;

	if (read(fd, 0, 0) || BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	while (1)
	{
		i_sep = ft_found_c(statik);
		if (i_sep != -1)
			break ;
		c_read = read(fd, buff, BUFFER_SIZE);
		if (c_read == 0)
			break ;
		statik_stck(&statik, buff, c_read);
	}
	if (!statik)
		return (NULL);
	line = ft_strret(&statik, c_read);
	return (line);
}
#include <stdio.h>

int	main()
{
	int	fd;
	char *line;

	fd = open("myfile.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s\n", line); 
		if (line == NULL)
			break;
		 free(line); 
	}
}