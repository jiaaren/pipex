/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:09:07 by jkhong            #+#    #+#             */
/*   Updated: 2021/04/30 15:34:33 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	size_t			i;
	unsigned char	*tmp_d;
	unsigned char	*tmp_s;

	if (!dest && !src)
		return (NULL);
	i = 0;
	tmp_d = (unsigned char *)dest;
	tmp_s = (unsigned char *)src;
	while (i < num)
	{
		tmp_d[i] = tmp_s[i];
		i++;
	}
	return (dest);
}
