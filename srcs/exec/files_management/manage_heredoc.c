/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:44:05 by ade-fran          #+#    #+#             */
/*   Updated: 2024/03/30 15:44:06 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_manage_heredoc(t_data data, int pipefd[2])
{
	if (dup2(data.heredoc[0], STDIN_FILENO) == -1)
	{
		close(data.heredoc[0]);
		return (ft_errors(DUP_ERR), 0);
	}
	close(data.heredoc[0]);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		return (ft_errors(DUP_ERR), 0);
	close(pipefd[1]);
	return (1);
}
