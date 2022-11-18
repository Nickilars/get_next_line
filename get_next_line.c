/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:40:15 by nrossel           #+#    #+#             */
/*   Updated: 2022/11/17 16:51:39 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*stck = NULL;
	char			*line;
	int				c_read;

	if (fd < 0 || fd == NULL || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	\\1. lire et ecrire 
	 



	close(fd);
}

void	read_n_stck(t_list **stck, int *c_read)
{
	char	*buff;

	if (!*fd || !*stck)
		return ;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return ;
	*c_read = read(fd, buff, BUFFER_SIZE);
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
		printf("%s", line); 
		if (line == NULL)
			break;
		 free(line); 
	}
}