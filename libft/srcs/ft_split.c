/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:00:07 by jkhong            #+#    #+#             */
/*   Updated: 2021/05/02 11:32:30 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char sep)
{
	return (c == sep || c == '\0');
}

static int	count_words(char const *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		if (!is_sep(*s, c) && is_sep(*(s + 1), c))
			words++;
		s++;
	}
	return (words);
}

static char	*add_word(const char *str, char c)
{
	char	*tmp;
	int		strlen;
	int		i;

	strlen = 0;
	while (!is_sep(*(str + strlen), c))
		strlen++;
	tmp = malloc(sizeof(char) * (strlen + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < strlen)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

void	fill_array(char const *s, char c, char **tmp)
{
	int	arr_i;

	arr_i = 0;
	if (!is_sep(*s, c))
	{
		tmp[arr_i] = add_word(s, c);
		if (tmp[arr_i])
			arr_i++;
	}
	if (*s)
		s++;
	while (*s)
	{
		if (!is_sep(*s, c) && is_sep(*(s - 1), c))
		{
			tmp[arr_i] = add_word(s, c);
			if (tmp[arr_i])
				arr_i++;
		}
		s++;
	}
	tmp[arr_i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**tmp;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	tmp = malloc(sizeof(char *) * (words + 1));
	if (!tmp)
		return (NULL);
	fill_array(s, c, tmp);
	return (tmp);
}
