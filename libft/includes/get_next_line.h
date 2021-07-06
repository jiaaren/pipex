/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:17:55 by jkhong            #+#    #+#             */
/*   Updated: 2021/06/20 20:23:15 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

int		get_next_line(int fd, char **line);
void	gnl_lstadd_back(t_list **lst, char *content);
void	gnl_lstclear(t_list **lst, void (*del)(void *));
int		ft_linesize(t_list *lst);
void	print_lst(t_list *lst);
void	ft_bzero(void *ptr, size_t num);
void	*ft_calloc(size_t count, size_t size);

#endif
