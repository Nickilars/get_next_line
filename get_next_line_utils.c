/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:48:55 by nrossel           #+#    #+#             */
/*   Updated: 2022/11/18 10:02:27 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*--------- 1 -----------*/
t_list	*ft_lstnew(char *s) 
{
	int		len_s;
	void	*lst;
	char	*new_s;

	len_s = ft_strlen(s);
	lst = malloc(sizeof(t_list));
	new_s = malloc((len_s + 1) * sizeof(char));
	if (!lst || !new_s)
		return (NULL);
	while (*s)
		*new_s++ = *s++;
	lst->content = new_s;
	lst->next = NULL;
	return (lst);
}

/*--------- 2 -----------*/
void	ft_lst_addback(t_list **lst, t_list *new)
{
	t_list	*ptr;

	ptr = *lst;
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new; 
}

/*--------- 3 -----------*/
int	ft_strlen(char *s)
{
	int	i;

	while (*s++)
		i++;
	return (i);
}

/*--------- 4 -----------*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len > (ft_strlen(s + start)))
		len = (ft_strlen(s + start));
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
