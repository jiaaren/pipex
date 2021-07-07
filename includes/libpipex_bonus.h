/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:42:11 by jkhong            #+#    #+#             */
/*   Updated: 2021/07/07 21:07:21 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPIPEX_H
# define LIBPIPEX_H

// free
# include <stdlib.h>
// execve, fork, dup, dup2 in unistd
# include <unistd.h>
// waitpid
# include <sys/wait.h>
// read
# include <fcntl.h>
// perror & strerror
# include <errno.h>
# include <string.h>
// utils
# include "libft.h" 

#endif