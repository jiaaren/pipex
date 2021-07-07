/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freesplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:00:07 by jkhong            #+#    #+#             */
/*   Updated: 2021/07/07 21:03:28 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freesplit(char **tmp_char)
{
	char	**ptr;

	ptr = tmp_char;
	while (*ptr)
		free(*ptr++);
	free(tmp_char);
}
