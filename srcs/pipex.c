/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:42:06 by jkhong            #+#    #+#             */
/*   Updated: 2021/07/06 17:22:44 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpipex.h"

/*
	Including path
	https://stackoverflow.com/c/42network/questions/1259


	1. to structure code
		a. have it run multiple shell commands
		b. incorporate redirection
		c. consider error handling
*/

int	read_file()
{
	return (0);	
}

// version 1 - to process shell commands one after another
// e.g. ./pipex "ls -l" "ls -l"
int	main(int argc, char *argv[])
{
	int		i;
	int		pid;
	char	**args;
	char	*path;

	i = 1;
	while (i < argc)
	{
		pid = fork();
		args = ft_split(argv[i], ' ');
		path = ft_strjoin("/bin/", args[0]);
		if (pid == 0) // i.e. child node
		{
			execve(path, args, NULL);
		}
		waitpid(pid, NULL, 0);
		free_split(args);
		free(path);
		i++;
	}
	// include error handling to inform user insufficient inputs
	// if (argc < 3)
	// {
	// 	ft_putstr_fd("./pipex [file1] [cmd1] [cmd2] [file2]\n", 2);
	// 	return (1);
	// }
	return (0);
}
