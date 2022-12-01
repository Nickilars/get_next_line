/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:40:15 by nrossel           #+#    #+#             */
/*   Updated: 2022/12/01 15:44:00 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*---------------- strdup ------------------*/
void	ft_strdup(char **statik, char *buffer)
{
	int		len;
	char	*new_str;
	int		i;

	if (!buffer)
		return ;
	len = BUFFER_SIZE + 1;
	buffer[BUFFER_SIZE] = 0;
	new_str = (char *)malloc(len * sizeof(char));
	if (!new_str)
		return ;
	i = 0;
	while (*buffer && len-- > 0)
		new_str[i++] = *buffer++;
	new_str[i] = 0;
	*statik = new_str;
}

/*---------------- isline ------------------*/
int	ft_isline(char *statik, int *c_read)
{
	int	i;

	i = 0;
	if (!statik)
		return (0);
	while (*statik)
	{
		if (*statik == '\n')
		{
			*c_read = i;
			return (1);
		}
		statik++;
		i++;
	}
	return (0);
}

/*---------------- statik_check ------------------*/
void	statik_check(char **statik, char *buffer)
{
	if (!*statik)
		ft_strdup(statik, buffer);
	else
		*statik = ft_strjoin(*statik, buffer);
}
/*---------------- get_next_line ------------------*/

char	*get_next_line(int fd)
{
	static char	*statik = NULL;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			c_read;

	if (fd < 1 || BUFFER_SIZE < 1)
		return (NULL);
	if (ft_isline(statik, &c_read))
	{
		ft_substr(&statik, &line, c_read);
		return (line);
	}
	while (1)
	{
		c_read = read(fd, buffer, BUFFER_SIZE);
		if (!(c_read))
			return (NULL);
		statik_check(&statik, buffer);
		if (ft_isline(statik, &c_read))
			break ;
	}
	ft_substr(&statik, &line, c_read);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("myfile.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		if (line == NULL)
			break ;
		free(line);
	}
}
