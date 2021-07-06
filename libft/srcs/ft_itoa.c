/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:42:34 by jkhong            #+#    #+#             */
/*   Updated: 2021/05/02 14:35:33 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	int_len(int n)
{
	int	len;

	len = 1;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	if (n < 0)
		len += 2;
	else
		len += 1;
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*tmp;

	len = int_len(n);
	tmp = malloc(sizeof(char) * len);
	if (!tmp)
		return (0);
	i = 1;
	if (n < 0)
		tmp[0] = '-';
	if (n == 0)
		tmp[0] = '0';
	while (n)
	{
		if (n % 10 < 0)
			tmp[len - i - 1] = -(n % 10) + '0';
		else
			tmp[len - i - 1] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	tmp[len - 1] = '\0';
	return (tmp);
}
