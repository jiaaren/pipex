/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:24:05 by jkhong            #+#    #+#             */
/*   Updated: 2021/04/30 15:35:03 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src,
					int c, size_t num)
{
	size_t			i;
	unsigned char	*d_tmp;
	unsigned char	*s_tmp;

	i = 0;
	d_tmp = (unsigned char *)dest;
	s_tmp = (unsigned char *)src;
	while (i < num)
	{
		d_tmp[i] = s_tmp[i];
		if (s_tmp[i] == (unsigned char)c)
			return (&d_tmp[i + 1]);
		i++;
	}
	return (0);
}
