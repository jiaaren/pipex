/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:42:06 by jkhong            #+#    #+#             */
/*   Updated: 2021/07/06 17:27:39 by jkhong           ###   ########.fr       */
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

/*
	Maybe handle errors in a separate function
	include error handling to inform user insufficient inputs
	if (argc < 3)
	{
		ft_putstr_fd("./pipex [file1] [cmd1] [cmd2] [file2]\n", 2);
		return (1);
	}
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
		// included waitpid here just in case execve runs finish before freeing below
		// if waitpid is not added, the sequence of runs will be off, i.e. the data will be freed before all executions
		// We can also actually just use wait() instead, since we are only dealing with 1 fork at a single time
		// waitpid helps if there are multiple forks running at the same time, where sequencing is important for us.
		waitpid(pid, NULL, 0);
		free_split(args);
		free(path);
		i++;
	}
	return (0);
}
