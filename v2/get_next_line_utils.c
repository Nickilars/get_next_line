/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:48:55 by nrossel           #+#    #+#             */
/*   Updated: 2022/11/28 17:02:41 by nrossel          ###   ########.fr       */
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

/*--------- 4. substr -----------*/

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