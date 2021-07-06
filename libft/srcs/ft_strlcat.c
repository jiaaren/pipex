/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:14:18 by jkhong            #+#    #+#             */
/*   Updated: 2021/04/30 15:45:51 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dst_len;
	while (*src && (i + 1 < dstsize))
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	return (src_len + dst_len);
}
