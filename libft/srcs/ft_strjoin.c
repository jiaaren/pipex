/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:13:36 by jkhong            #+#    #+#             */
/*   Updated: 2021/04/30 18:38:29 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	tmp = malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (*s1)
	{	
		tmp[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		tmp[i] = *s2;
		s2++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
