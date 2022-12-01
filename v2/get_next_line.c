/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:40:15 by nrossel           #+#    #+#             */
/*   Updated: 2022/12/01 09:54:34 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*---------------- strdup ------------------*/
void	ft_strdup(char **statik, char *buffer)
{
	int	len;

	len = BUFFER_SIZE + 1
	*statik = malloc(len * sizeof(char));
	while (*buffer && len > 0)
	{
		**statik++ = *buffer++;
		len--;
	}
	**statik = 0;
	*statik - ft_strlen(buffer);
}
/*---------------- isline ------------------*/
int	ft_isline(char *statik, int *c_read)
{
	int	i;

	i = 0;
	while(*statik)
	{
		if(*statik == '\n')
		{
			*c_read = i;
			return (1);
		}
		statik++;
		i++;
	}
	return (0);
}
/*---------------- s ------------------*/
void	unknow(char **statik, char **line, int index)
{
	char *tmp = NULL;

	if (!*statik)
		return (NULL);
	ft_substr(*statik, *line, index);
}
/*---------------- get_next_line ------------------*/

char	*get_next_line(int fd)
{
	static char	*statik = NULL;
	char		buffer[BUFFER_SIZE + 1] = NULL;
	char		*line = NULL;
	int			c_read;

	c_read = 0;
	if (fd < 1 || BUFFER_SIZE < 1)
		RETURN (NULL);
	if (ft_isline(statik, &c_read))
	{
		ft_substr(statik, line, c_read);
		return (line);
	}
	while (1)
	{
		c_read = read(fd, buffer, BUFFER_SIZE);
		if (c_read == 0)
			return (NULL);
		if (!statik)
			ft_strdup(&statik, buffer);
		else
		{
			
		}
		
	}
	return ();
}


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