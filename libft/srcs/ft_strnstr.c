/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 12:14:58 by jkhong            #+#    #+#             */
/*   Updated: 2021/05/02 11:37:08 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hay_i;
	size_t	ned_i;

	if (!*needle)
		return ((char *)haystack);
	hay_i = 0;
	while (haystack[hay_i] && hay_i < len)
	{
		ned_i = 0;
		while (haystack[hay_i + ned_i] == needle[ned_i]
			&& (hay_i + ned_i) < len
			&& needle[ned_i] && haystack[hay_i + ned_i])
		{
			ned_i++;
			if (needle[ned_i] == '\0')
				return ((char *)&haystack[hay_i]);
		}
		hay_i++;
	}
	return (0);
}
