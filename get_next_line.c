/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:40:15 by nrossel           #+#    #+#             */
/*   Updated: 2022/11/18 16:37:50 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*---------------- strdup ------------------*/

char	*ft_strdup(const char *s)
{
	char	*new_s;

	if (!s || !*s)
		return (NULL);
	new_s = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!new_s)
		return (NULL);
	while (*s)
	{
		*new_s++ = s++;
	}
	return (new_s);
}
/*---------------- read_n_stck ------------------*/

void	read_n_stck(int fd, int *c_read)
{
	char	*buff;
	char	*tmp;
	int		index;

	buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return ;
	*c_read = read(fd, buff, BUFFER_SIZE);
	if (*c_read == -1)
	{
		free(buff)
		return ;
	}
	tmp = ft_strdup(buff);
	if (!tmp)
	{
		free(buff);
		return ;
	}
	return (buff);
}

void	if_n_found(char *s, int index, char *ligne)
{
	if (ft_found_n(tmp,&index))
	{
		ft_strjoin(tmp, (ft_substr(buff, 0, index)));
		line = ft_strdup(ft_substr(buff, index, ft_strlen(buff)));
	}
	else
	{
		ft_strjoin(tmp, buff);
	}
}


	
	
}
/*---------------- get_next_line ------------------*/

char	*get_next_line(int *fd)
{
	static char	*line;
	int			c_read;

	if (*fd < 0 || *fd == NULL || read(*fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	read_n_stck(*fd, &c_read);
	//1. lire et stocker dans malloc
	//2. si '\n' , substr malloc dans une nouvelle liste
	//3. liberer malloc
	//4. repeter l'etape 1 à 3 jusqu'a tomber sur un $.
	 



	close(fd);
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
		line = get_next_line(&fd);
		printf("%s", line); 
		if (line == NULL)
			break;
		 free(line); 
	}
}