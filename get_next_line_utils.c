/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:48:55 by nrossel           #+#    #+#             */
/*   Updated: 2022/11/18 16:37:53 by nrossel          ###   ########.fr       */
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

/*--------- 2. calloc + bzero -----------*/
void	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	int		n;

	if (!count || !size)
		return (NULL);
	n = count + 1;
	s = malloc(count * size);
	if (!s)
		return (s);
	while (n > 0)
	{
		*s = 0;
		s++;
		n--;
	}
	return (s);
}

/*--------- 3. strjoin -----------*/
char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	len_max;
	char	*new_s;

	len_max = (ft_strlen((char *)s1) + ft_strlen((char *)s2));
	new_s = ft_calloc((len_max + 1), sizeof(char));
	if (!new_s)
		return (NULL);
	i = 0;
	while (*s2 && i++ < len_max )
	{
		if (*s1)
			*new_s++ = *s1++;
		else
			*new_s++ = *s2++;
	}
	return (new_s - i);
}
/*--------- 4. substr -----------*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*new_s;

	if (!s)
		return (NULL);
	if (start > ft_strlen((char *)s))
		return (ft_calloc(1, 1));
	if (len > (ft_strlen((char *)s + start)))
		len = (ft_strlen((char *)s + start));
	new_s = ft_calloc(len + 1, sizeof(char));
	if (!new_s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_s[i] = s[start + i];
		i++;
	}
	return (new_s);
}
/*--------- 5. found_c -----------*/

int	ft_found_n(char *s, int *index)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == '\n')
		{
			*index = i;
			return (1);
		}
		i++;
		s++;
	}
	return (0);
}
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char *s1 = "Bienvenu";
	char *s2 = " a toi";
	char *s3 = "Ma fois\nc'est la vie";
	int len;

	len = 0;
	printf("%s", ft_strjoin(s1, s2));
	printf("\n");
	printf("%zu", ft_strlen(s3));
	printf("\n");
	printf("%s", ft_substr(s3, 0, 7));
	printf("\n");
	printf("%d", ft_found_c(s3));
	return (0);
}