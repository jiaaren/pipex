/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 12:07:02 by jkhong            #+#    #+#             */
/*   Updated: 2021/04/30 12:11:07 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char	*tmp_ptr;

	tmp_ptr = 0;
	while (*str)
	{
		if (*str == c)
			tmp_ptr = (char *)str;
		str++;
	}
	if (tmp_ptr != 0)
		return (tmp_ptr);
	if (c == '\0')
		return ((char *)str);
	return (0);
}
