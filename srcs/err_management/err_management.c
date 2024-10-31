/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:34:36 by ade-fran          #+#    #+#             */
/*   Updated: 2024/03/14 15:34:38 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_errors(int err)
{
	if (err == SPLIT_ENV)
		return (perror("Split Envp Path"));
	if (err == SEARCH_PATH)
		return (perror("Search Path"));
	if (err == PIPE_ERR)
		return (perror("Pipe"));
	if (err == FORK_ERR)
		return (perror("Fork"));
	if (err == EXEC_ERR)
		return (perror("Execve"));
	if (err == DUP_ERR)
		return (perror("Dup"));
	if (err == GNL_ERR)
		return (perror("GNL"));
}

void	ft_cmd_errors(int err, char *arg, int *error)
{
	if (err == CMD_NOT_FOUND)
	{
		*error = CMD_NOT_FOUND;
		ft_printf("%s: Command not found\n", 2, arg);
		return ;
	}
	if (err == CMD_ACCESS)
	{
		*error = CMD_NOT_FOUND;
		ft_printf("pipex: ", 2);
		perror(arg);
		return ;
	}
	if (err == PERM_DENIED)
	{
		*error = PERM_DENIED;
		ft_printf("pipex: ", 2);
		perror(arg);
		return ;
	}
}

void	ft_file_errors(char *file)
{
	return (perror(file));
}

void	ft_null_env_err(t_child c_data, t_data data, int pipefd[2], int *err)
{
	ft_cmd_errors(CMD_ACCESS, c_data.cmd[0], err);
	ft_exit_child(c_data, data, pipefd, CMD_NOT_FOUND);
}

void	ft_execve_err(t_child c_data, t_data data, int pipefd[2], int *err)
{
	if (access(c_data.path, F_OK) == -1)
		ft_cmd_errors(CMD_NOT_FOUND, c_data.cmd[0], err);
	else
		ft_cmd_errors(PERM_DENIED, c_data.cmd[0], err);
	ft_exit_child(c_data, data, pipefd, *err);
}
