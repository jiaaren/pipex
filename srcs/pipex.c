/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:42:06 by jkhong            #+#    #+#             */
/*   Updated: 2021/07/08 00:27:31 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpipex.h"

static char	**g_path;

int	write_file(char *filename, int fd)
{
	int		new_file;
	char	c;

	new_file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (new_file == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putchar_fd('\n', 2);
		return (-1);
	}
	if (fd != -1)
		while (read(fd, &c, 1) > 0)
			write(new_file, &c, 1);
	close(new_file);
	return (0);
}

void	read_file(char *filename, int dup_fd[2])
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putchar_fd('\n', 2);
	}
	dup2(fd, dup_fd[0]);
	close(fd);
}

int	process_child(char *argv[], int dup_fd_r[2], int dup_fd_w[2], int count)
{
	char	**args;
	char	**paths;
	int		pid;

	args = ft_split(argv[count], ' ');
	paths = make_path(g_path, args[0]);
	pid = fork();
	if (pid == 0)
	{
		close(dup_fd_r[1]);
		close(dup_fd_w[0]);
		dup2(dup_fd_w[1], STDOUT_FILENO);
		dup2(dup_fd_r[0], STDIN_FILENO);
		close(dup_fd_r[0]);
		close(dup_fd_w[1]);
		exec_cmd(args, paths);
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
	ft_freesplit(args);
	ft_freesplit(paths);
	return (pid);
}

int	cycle_cmd(int argc, char *argv[], int dup_fd_r[2], int dup_fd_w[2])
{
	int		i;
	int		tmp_fd;
	int		pid;

	i = 2;
	while (i < argc - 1)
	{
		if (i != 2)
		{
			pipe(dup_fd_r);
			pipe(dup_fd_w);
			dup2(tmp_fd, dup_fd_r[0]);
			close(tmp_fd);
		}
		pid = process_child(argv, dup_fd_r, dup_fd_w, i);
		close(dup_fd_r[1]);
		close(dup_fd_r[0]);
		close(dup_fd_w[1]);
		tmp_fd = dup(dup_fd_w[0]);
		close(dup_fd_w[0]);
		waitpid(pid, NULL, 0);
		i++;
	}
	return (tmp_fd);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		dup_fd_r[2];
	int		dup_fd_w[2];
	int		tmp_fd;

	if (argc != 5)
	{
		ft_putstr_fd("./pipex [file1] [cmd1] [cmd2] [file2]\n", 2);
		return (1);
	}
	g_path = split_path(envp);
	pipe(dup_fd_r);
	pipe(dup_fd_w);
	read_file(argv[1], dup_fd_r);
	tmp_fd = cycle_cmd(argc, argv, dup_fd_r, dup_fd_w);
	if (write_file(argv[argc - 1], tmp_fd) == -1)
		close(tmp_fd);
	close(tmp_fd);
	ft_freesplit(g_path);
	return (0);
}
