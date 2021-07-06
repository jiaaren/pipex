/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:05:29 by jkhong            #+#    #+#             */
/*   Updated: 2021/05/06 10:13:33 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tmp_d;
	unsigned char	*tmp_s;

	if (!dst && !src)
		return (NULL);
	tmp_d = (unsigned char *)dst;
	tmp_s = (unsigned char *)src;
	i = 0;
	while (src >= dst && i < len)
	{
		tmp_d[i] = tmp_s[i];
		i++;
	}
	while (src < dst && len > 0)
	{
		tmp_d[len - 1] = tmp_s[len - 1];
		len--;
	}
	return (dst);
}
