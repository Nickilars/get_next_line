/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:40:15 by nrossel           #+#    #+#             */
/*   Updated: 2022/11/21 16:01:49 by nrossel          ###   ########.fr       */
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
/*---------------- read_n_stck ------------------*/

int	read_n_stck(int fd, char **tmp)
{
	char	buff[BUFFER_SIZE + 1];

	if (read(fd, buff, BUFFER_SIZE) == -1)
		return (-1);

	if (*tmp == NULL)
	{
		*tmp = ft_strdup(buff);
		return (0);
	}
	else
		ft_strjoin (*tmp, buff);
	return (0);
}
/*---------------- ft_n_found ------------------*/

void	ft_n_found(char **line, char **tmp, int *index)
{
	if (!*tmp)
		return ;
	*line = ft_strdup(ft_substr(*tmp, 0, *index));
	if (!*line)
	{
		free(*tmp);
		*tmp = NULL;
		return ;
	}
	*tmp = ft_substr(*tmp, *index, ft_strlen(*tmp));
	if (!*tmp)
	{
		free(*line);
		return ;
	}	
}

/*---------------- get_next_line ------------------*/

char	*get_next_line(int fd)
{
	static char	*tmp;
	int			index;
	char		*line;

	line = NULL;
	if (fd < 0 || read(fd, 0, 0) <0 || BUF1FER_SIZE <= 0)
		return (NULL);
	while (read(fd, tmp, 0) > 0)
	{
		if (read_n_stck(fd, &tmp) == -1)
			return (NULL);
		if (ft_found_c(tmp, &index))
			break ;
	}
	ft_n_found(&line, &tmp, &index);
	close(fd);
	return (line);
}
// #include <stdio.h>
// 
// int	main()
// {
	// int	fd;
	// char *line;
// 
	// fd = open("myfile.txt", O_RDONLY);
	// while (1)
	// {
		// line = get_next_line(fd);
		// printf("%s\n", line); 
		// if (line == NULL)
			// break;
		//  free(line); 
	// }
// }