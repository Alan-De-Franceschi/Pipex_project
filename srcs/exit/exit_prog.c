/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:10:42 by ade-fran          #+#    #+#             */
/*   Updated: 2024/03/27 14:10:44 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit_prog(int pipefd[2], int prev_fd, int pid, int err)
{
	int	exit_status;

	if (err == PIPE_ERR || err == FORK_ERR || err == DUP_ERR)
	{
		ft_errors(err);
		if (prev_fd != -1)
			close(prev_fd);
		if (err == FORK_ERR || err == DUP_ERR)
			ft_close_pipe(pipefd);
		if (err == PIPE_ERR && pid == -1)
			exit(1);
		exit_status = ft_get_exit_status(pid);
		exit(exit_status);
	}
	exit_status = ft_get_exit_status(pid);
	exit(exit_status);
}
