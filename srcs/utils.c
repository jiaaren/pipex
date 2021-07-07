/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 23:47:53 by jkhong            #+#    #+#             */
/*   Updated: 2021/07/08 00:20:47 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static char	*ft_strjoin2(char const *s1, char const *s2)
{
	int		len;
	int		i;
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	tmp = malloc(sizeof(char) * (len + 1 + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (*s1)
	{	
		tmp[i] = *s1++;
		i++;
	}
	tmp[i] = '/';
	i++;
	while (*s2)
	{
		tmp[i] = *s2++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	**split_path(char *envp[])
{
	int	i;
	
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	return (ft_split(envp[i], ':'));
}

char	**make_path(char **path_envp, char *cmd)
{
	int		i;
	int		path_len;
	char	**new_path;

	path_len = 0;
	while (path_envp[path_len])
		path_len++;
	new_path = malloc(sizeof(char *) * (path_len + 1));
	i = 0;
	while (i < path_len)
	{
		new_path[i] = ft_strjoin2(path_envp[i], cmd);
		i++;
	}
	new_path[i] = NULL;
	return (new_path);
}

int	exec_cmd(char *args[], char *paths[])
{
	int i;

	i = 0;
	while (paths[i])
	{
		execve(paths[i], args, NULL);
		i++;
	}
	return (-42);
}

// int main(int argc, char *argv[], char *envp[])
// {
// 	char *args[] = 
// 	{
// 		"cat",
// 		"-l",
// 		NULL
// 	};

// 	char **tmp;
// 	tmp = split_path(envp);

// 	for (int i = 0; tmp[i]; i++)
// 		printf("%s\n", tmp[i]);
	
// 	char **paths;
// 	paths = make_path(tmp, args[0]);
	
// 	for (int i = 0; paths[i]; i++)
// 		printf("%s\n", paths[i]);
	
// 	printf("%i\n", exec_cmd(args, paths));
// 	return (0);
// }