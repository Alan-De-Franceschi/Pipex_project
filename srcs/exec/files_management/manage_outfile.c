/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_outfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:56:56 by ade-fran          #+#    #+#             */
/*   Updated: 2024/03/25 15:57:05 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_manage_outfile(t_child *c_data, t_data data, char *file, int pipefd[2])
{
	close(pipefd[1]);
	if (data.if_heredoc == 0)
		c_data->outfile = open(file, O_CREAT | O_TRUNC | O_RDWR, 0744);
	else if (data.if_heredoc == 1)
		c_data->outfile = open(file, O_CREAT | O_APPEND | O_RDWR, 0744);
	if (c_data->outfile == -1)
		return (ft_file_errors(file), 0);
	if (access(file, F_OK | R_OK | W_OK) == -1)
		return (ft_file_errors(file), 0);
	if (dup2(c_data->outfile, STDOUT_FILENO) == -1)
		return (ft_errors(DUP_ERR), 0);
	close(c_data->outfile);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		return (ft_errors(DUP_ERR), 0);
	close(pipefd[0]);
	return (1);
}
