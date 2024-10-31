/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:52:00 by ade-fran          #+#    #+#             */
/*   Updated: 2024/03/22 14:52:02 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_first_child(t_data data, char *str_cmd, int pipefd[2])
{
	t_child	child_data;
	int		err;

	ft_init_child_data(&child_data);
	data.paths = ft_split_env(data.envp);
	if (data.heredoc[0] != -1)
	{
		if (!ft_manage_heredoc(data, pipefd))
			ft_exit_child(child_data, data, pipefd, 1);
	}
	else
	{
		if (!ft_manage_infile(&child_data, data.av[1], pipefd))
			ft_exit_child(child_data, data, pipefd, 1);
	}
	child_data.cmd = ft_split_cmd(str_cmd, &err);
	if (!child_data.cmd)
		ft_exit_child(child_data, data, pipefd, err);
	if (!data.paths && access(child_data.cmd[0], F_OK | X_OK) == -1)
		ft_null_env_err(child_data, data, pipefd, &err);
	child_data.path = ft_search_path(data.paths, child_data.cmd[0], &err);
	if (!child_data.path)
		ft_exit_child(child_data, data, pipefd, err);
	execve(child_data.path, child_data.cmd, data.envp);
	ft_execve_err(child_data, data, pipefd, &err);
}

static void	ft_last_child(t_data data, char *str_cmd, int pipefd[2])
{
	t_child	child_data;
	int		err;

	ft_init_child_data(&child_data);
	data.paths = ft_split_env(data.envp);
	if (!ft_manage_outfile(&child_data, data, data.av[data.ac - 1], pipefd))
		ft_exit_child(child_data, data, pipefd, 1);
	child_data.cmd = ft_split_cmd(str_cmd, &err);
	if (!child_data.cmd)
		ft_exit_child(child_data, data, pipefd, err);
	if (!data.paths && access(child_data.cmd[0], F_OK | X_OK) == -1)
		ft_null_env_err(child_data, data, pipefd, &err);
	child_data.path = ft_search_path(data.paths, child_data.cmd[0], &err);
	if (!child_data.path)
		ft_exit_child(child_data, data, pipefd, err);
	execve(child_data.path, child_data.cmd, data.envp);
	ft_execve_err(child_data, data, pipefd, &err);
}

static void	ft_inter_child(t_data data, char *str_cmd, int pipefd[2])
{
	t_child	child_data;
	int		err;

	ft_init_child_data(&child_data);
	data.paths = ft_split_env(data.envp);
	if (!ft_inter_file(pipefd))
		ft_exit_child(child_data, data, pipefd, 1);
	child_data.cmd = ft_split_cmd(str_cmd, &err);
	if (!child_data.cmd)
		ft_exit_child(child_data, data, pipefd, err);
	if (!data.paths && access(child_data.cmd[0], F_OK | X_OK) == -1)
		ft_null_env_err(child_data, data, pipefd, &err);
	child_data.path = ft_search_path(data.paths, child_data.cmd[0], &err);
	if (!child_data.path)
		ft_exit_child(child_data, data, pipefd, err);
	execve(child_data.path, child_data.cmd, data.envp);
	ft_execve_err(child_data, data, pipefd, &err);
}

void	ft_manage_child(t_data data, char *str_cmd, int pipefd[2], int nb_cmd)
{
	if (data.index_cmd == nb_cmd)
		ft_first_child(data, str_cmd, pipefd);
	else if (data.index_cmd == 1)
		ft_last_child(data, str_cmd, pipefd);
	else
		ft_inter_child(data, str_cmd, pipefd);
}
