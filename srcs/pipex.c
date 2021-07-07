/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:42:06 by jkhong            #+#    #+#             */
/*   Updated: 2021/07/07 12:41:35 by jkhong           ###   ########.fr       */
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
		d. valgrind - Warning: invalid file descriptor -1 in syscall close()
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

void	output_file(int fd)
{
	char c;
	while (read(fd, &c, 1) > 0)
		write(1, &c, 1); // 1 is write
}

// wipe out file if there is one
// include error checking for file, e.g. file name too long
void	write_file(char *filename, int fd)
{
	int		new_file;
	char	c;
	// need O_TRUNC to reset file to zero
	new_file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0777); // append for bonus
	while (read(fd, &c, 1) > 0)
		write(new_file, &c, 1);
}

int	read_file(char *filename, int dup_fd[2])
{
	int		fd;
	// initialising fd, closing the pipe and duplicating it to dup_fd via writing into [1]
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putchar_fd('\n', 2);
		return (-1);
	}
	// only can dup2 if fd is within range, need to initialise it properly before, i.e. using pipe, cannot just declare an integer and duplicate it afterwards
	dup2(fd, dup_fd[0]);
	close(fd);
	// char c;
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
	int		tmp_fd; 		// for initial read, not required here because it will be closed off
	int		dup_fd_r[2];
	int		dup_fd_w[2];

	if (argc < 5)
		return (1);
	// forgot to pipe it previously
	pipe(dup_fd_r);
	pipe(dup_fd_w);
	if (read_file(argv[1], dup_fd_r) == -1)
		return (2);
	i = 2; // 2 i.e. index of the first shell command
	while (i < argc - 1) // -1 to consider last file as filename
	{
		if (i != 2)
		{
			pipe(dup_fd_r);
			pipe(dup_fd_w);
			dup2(tmp_fd, dup_fd_r[0]);
			// close after transferring to dup_fd_r[0]
			close(tmp_fd);
		}
		args = ft_split(argv[i], ' ');
		path = ft_strjoin("/bin/", args[0]);
		pid = fork();
		if (pid == 0) // i.e. child node
		{
			// close unused ports for child, i.e. write
			close(dup_fd_r[1]);
			close(dup_fd_w[0]);

			dup2(dup_fd_w[1], STDOUT_FILENO);
			dup2(dup_fd_r[0], STDIN_FILENO); // change my dup_fd_r into STDIN
			// after duplicating it, close unused port
			close(dup_fd_r[0]);
			close(dup_fd_w[1]);
			execve(path, args, NULL);
			ft_putstr_fd(args[0], 2);
			ft_putstr_fd(": command not found\n", 2);
			
			// after execve, program will just stop
			return (3);
		}
		// close unused
		close(dup_fd_r[1]);
		// used
		close(dup_fd_r[0]);
		close(dup_fd_w[1]);
		// output_file(dup_fd_w[0]);
		tmp_fd = dup(dup_fd_w[0]);
		close(dup_fd_w[0]);
		// included waitpid here just in case execve runs finish before freeing below
		// if waitpid is not added, the sequence of runs will be off, i.e. the data will be freed before all executions
		// We can also actually just use wait() instead, since we are only dealing with 1 fork at a single time
		// waitpid helps if there are multiple forks running at the same time, where sequencing is important for us.		

		// if one child process fails, no need to terminat the remainder, continue executing
		waitpid(pid, NULL, 0);
		free_split(args);
		free(path);
		i++;
	}
	// be aware of how often we call write or read, the file pointer will always move and we need to pay close attention.
	// output_file(tmp_fd); 
	// write to file
	write_file(argv[argc - 1], tmp_fd);
	close(tmp_fd);
	// char c;
	// while (read(dup_fd[0], &c, 1) > 0)
	// 	write(1, &c, 1); // 1 is write
	return (0);
}

// we can close fd and the file?
