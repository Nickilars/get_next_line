/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:39:26 by nrossel           #+#    #+#             */
/*   Updated: 2022/12/13 11:42:24 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*---------------- 1. strchr ------------------*/
int	ft_strchr(const char *str)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

/*---------------- 2. join_2_str ------------------*/
void	ft_check_statik(char **dest, char *src, int c_read)
{
	char	*tmp;

	if (!src || c_read < 1)
		return ;
	src[c_read] = '\0';
	if (!*dest)
		*dest = ft_substr(src, 0, c_read);
	else
	{
		tmp = ft_strjoin(*dest, src);
		free(*dest);
		*dest = tmp;
	}
}

/*---------------- 3. ------------------*/
char	*ft_returnline(char **statik, int c_read)
{
	char	*ret;
	char	*tmp;
	int		index;

	if (!**statik || c_read == -1)
	{
		free(*statik);
		return (NULL);
	}
	index = ft_strchr(*statik) + 1;
	if (index == 0)
		index = ft_strlen(*statik);
	ret = ft_substr(*statik, 0, index);
	tmp = ft_substr(*statik, index, (ft_strlen(*statik) - index));
	free(*statik);
	if (c_read == 0 || *tmp == 0)
	{
		free(tmp);
		*statik = NULL;
		return (ret);
	}
	*statik = tmp;
	return (ret);
}

/*---------------- 4. get_next_line ------------------*/
char	*get_next_line(int fd)
{
	static char	*statik[4096];
	char		buffer[BUFFER_SIZE + 1];
	int			c_read;
	int			c_found;

	if (read(fd, 0, 0) || fd < 0 || BUFFER_SIZE < 1 || fd > 4096)
	{
		free(statik[fd]);
		statik[fd] = NULL;
		return (NULL);
	}
	while (1)
	{
		c_found = ft_strchr(statik[fd]);
		if (c_found > -1)
			break ;
		c_read = read(fd, buffer, BUFFER_SIZE);
		if (c_read <= 0)
			break ;
		ft_check_statik(&statik[fd], buffer, c_read);
	}
	if (!statik[fd])
		return (NULL);
	return (ft_returnline(&statik[fd], c_read));
}

int	main(int ac, char **av)
{
	(void) ac;
	(void) av;
	int		fd[10];
	char	*line;

	while (1)
	{
		fd[0] = open("a.txt", O_RDONLY);
		fd[1] = open("b.txt", O_RDONLY);
		while (1)
		{
			line = get_next_line(fd[0]);
			printf("%s\n", line);
			if (line == NULL)
			free(line);
			line = get_next_line(fd[1]);
			printf("%s\n", line);
			if (line == NULL)	
				break ;
			free(line);
		}
	}
}
