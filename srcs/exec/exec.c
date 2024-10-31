/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:38:30 by ade-fran          #+#    #+#             */
/*   Updated: 2024/03/19 15:38:33 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_parent_routine(int pipefd[2], int *previous_fd, int pid,
	t_data data)
{
	if (*previous_fd != -1)
		close(*previous_fd);
	if (data.index_cmd != 1)
		*previous_fd = dup(pipefd[0]);
	if (*previous_fd == -1)
		ft_exit_prog(pipefd, *previous_fd, pid, DUP_ERR);
	ft_close_pipe(pipefd);
	if (data.index_cmd == data.nb_cmd)
		close(data.heredoc[0]);
}

static void	ft_child_routine(t_data data, int pipefd[2], int prev_fd, int i)
{
	close(pipefd[0]);
	if (data.nb_cmd != data.index_cmd)
		pipefd[0] = prev_fd;
	ft_manage_child(data, data.av[i], pipefd, data.nb_cmd);
}

static void	ft_make_pipe(int pipefd[2], int prev_fd, int pid, int nb_cmd)
{
	if (nb_cmd > 1)
	{
		if (pipe(pipefd) == -1)
			ft_exit_prog(pipefd, prev_fd, pid, PIPE_ERR);
	}
}

void	ft_exec_cmd(t_data data)
{
	int		pid;
	int		pipefd[2];
	int		i;
	int		previous_pipefd;

	if (data.heredoc[0] != -1)
		i = 3;
	else
		i = 2;
	previous_pipefd = -1;
	pid = -1;
	while (data.index_cmd > 0)
	{
		ft_make_pipe(pipefd, previous_pipefd, pid, data.index_cmd);
		pid = fork();
		if (pid == -1)
			ft_exit_prog(pipefd, previous_pipefd, pid, FORK_ERR);
		if (pid > 0)
			ft_parent_routine(pipefd, &previous_pipefd, pid, data);
		if (pid == 0)
			ft_child_routine(data, pipefd, previous_pipefd, i);
		data.index_cmd--;
		i++;
	}
	ft_exit_prog(pipefd, previous_pipefd, pid, 0);
}
