/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 10:01:56 by jkhong            #+#    #+#             */
/*   Updated: 2021/04/30 15:38:01 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t num)
{
	unsigned char	*tmp_s;
	unsigned char	tmp_c;
	size_t			i;

	tmp_s = (unsigned char *)str;
	tmp_c = (unsigned char)c;
	i = 0;
	while (i < num)
	{
		if (tmp_s[i] == tmp_c)
			return (&tmp_s[i]);
		i++;
	}
	return (0);
}
