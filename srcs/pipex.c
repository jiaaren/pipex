/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:42:06 by jkhong            #+#    #+#             */
/*   Updated: 2021/07/06 16:04:45 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpipex.h"

int	main(int argc, char *argv[])
{
	// include error handling to inform user insufficient inputs
	if (argc < 3)
	{
		ft_putstr_fd("./pipex [file1] [cmd1] [cmd2] [file2]\n", 2);
		return (1);
	}
	return (0);
}