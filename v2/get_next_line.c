/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:40:15 by nrossel           #+#    #+#             */
/*   Updated: 2022/11/28 14:41:44 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*---------------- strdup ------------------*/
void	ft_strdup(char *statik, char *buffer)
{
	int b_len;

	b_len = ft_strlen(buffer);
	statik = malloc((b_len + 1) * sizeof(char));
	while (*buffer && b_len-- > 0)
	{
		*statik++ = *buffer++;
	}
	*statik = 0;
}
/*---------------- ft_isline ------------------*/
int	ft_isline(char *statik)
{
	while(*statik)
	{
		if(*statik == '\n')
			return (1);
		statik++;
	}
	return (0);
}
/*----------------  ------------------*/
int
{

}
/*---------------- get_next_line ------------------*/

char	*get_next_line(int fd)
{
	static char	*statik = NULL;
	char		buffer[BUFFER_SIZE] = NULL;
	char		*line = NULL;
	int			c_read;

	c_read = 0;
	if (fd <= 0 || BUFFER_SIZE <= 0)
		RETURN (NULL);
	if (ft_isline(statik))
	{
		;
		return ();
	}
	while (1)
	{
		c_read = read(fd, buffer, BUFFER_SIZE);
		if (c_read == 0)
			return (NULL);
		if (!statik)
			ft_strdup(statik, buffer);
		
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