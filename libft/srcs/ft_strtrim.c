/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:39:14 by jkhong            #+#    #+#             */
/*   Updated: 2021/04/30 18:59:57 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static void	start_end(char const *s1, char const *set, int *start, int *end)
{
	int	i;

	*start = 0;
	*end = 0;
	i = 0;
	while (in_set(*(s1 + i++), set))
		(*start)++;
	i = ft_strlen(s1) - 1;
	while (in_set(*(s1 + i--), set))
		(*end)++;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	int		i;
	char	*tmp;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	start_end(s1, set, &start, &end);
	i = 0;
	if ((start + end) > len || len == 0)
		len = 0;
	else
		len = len - start - end;
	tmp = malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	while (i < len)
	{
		tmp[i] = s1[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
