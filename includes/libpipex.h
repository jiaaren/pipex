/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:42:11 by jkhong            #+#    #+#             */
/*   Updated: 2021/07/06 17:17:45 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPIPEX_H
# define LIBPIPEX_H

// free
# include <stdlib.h>
// execve, fork in unistd
# include <unistd.h>
// waitpid
# include <sys/wait.h>
// to remove
# include <stdio.h>

# include "libft.h" 

void	free_split(char **tmp_char);

#endif