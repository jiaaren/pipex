/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:19:59 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/09 21:37:15 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_lstadd_back(t_list **lst, char *content)
{
	t_list	*new;
	t_list	*tmp;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->content = content;
	new->next = NULL;
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	gnl_lstclear(t_list **lst, void (*del)(void *))
{	
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

int	ft_linesize(t_list *lst)
{
	int		len;
	char	*str;

	len = 0;
	while (lst)
	{
		str = lst->content;
		while (*str != '\n' && *str != '\0')
		{
			str++;
			len++;
		}
		lst = lst->next;
	}
	return (len);
}
