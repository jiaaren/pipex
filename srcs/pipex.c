/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:42:06 by jkhong            #+#    #+#             */
/*   Updated: 2021/07/06 20:02:49 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpipex.h"

/*
	Including path
	https://stackoverflow.com/c/42network/questions/1259


	1. to structure code
		a. have it run multiple shell commands
		b1. implement redirection from file first
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

/*
	int	fd;
	int fd2;
	// initialising fd, closing the pipe and duplicating it to dup_fd via writing into [1]
	fd = open(filename, O_RDONLY);
	printf("fd %i fd2 %i fd[0] %i\n", fd, fd2, dup_fd[0]);
	dup2(fd, dup_fd[0]);
	fprintf(stderr, "errno = %s\n", strerror(errno));
	printf("fd %i fd2 %i fd[0] %i\n", fd, fd2, dup_fd[0]);
*/

int	read_file(char *filename, int dup_fd[2])
{
	int		fd;
	char	c;
	// initialising fd, closing the pipe and duplicating it to dup_fd via writing into [1]
	fd = open(filename, O_RDONLY);
	// only can dup2 if fd is within range, need to initialise it properly before, i.e. using pipe, cannot just declare an integer and duplicate it afterwards
	dup2(fd, dup_fd[0]);
	close(fd);
	// while (read(dup_fd[0], &c, 1) > 0)
	// 	write(1, &c, 1); // 1 is write
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
	int		fd; 		// for initial read, not required here because it will be closed off
	int		dup_fd[2];

	// forgot to pipe it previously
	pipe(dup_fd);
	read_file(argv[1], dup_fd);

	i = 2; // 2 i.e. index of the first shell command
	while (i < argc)
	{
		pid = fork();
		args = ft_split(argv[i], ' ');
		path = ft_strjoin("/bin/", args[0]);
		if (pid == 0) // i.e. child node
		{
			dup2(dup_fd[0], STDIN_FILENO); // change my dup_fd into STDIN
			// after duplicating it, close unused port
			close(dup_fd[0]);
			// close unused ports for child, i.e. write
			close(dup_fd[1]);
			execve(path, args, NULL);
			// after execve, program will just stop
			return (0);
		}
		// included waitpid here just in case execve runs finish before freeing below
		// if waitpid is not added, the sequence of runs will be off, i.e. the data will be freed before all executions
		// We can also actually just use wait() instead, since we are only dealing with 1 fork at a single time
		// waitpid helps if there are multiple forks running at the same time, where sequencing is important for us.
		close(dup_fd[0]);
		close(dup_fd[1]);
		waitpid(pid, NULL, 0);
		free_split(args);
		free(path);
		i++;
	}
	return (0);
}
