/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:37:14 by ade-fran          #+#    #+#             */
/*   Updated: 2024/03/24 14:37:16 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit_child(t_child c_data, t_data data, int pipefd[2], int status)
{
	ft_free_strtab(data.paths);
	ft_free_strtab(c_data.cmd);
	free(c_data.path);
	if (c_data.infile != -1)
		close(c_data.infile);
	if (c_data.outfile != -1)
		close(c_data.outfile);
	if (pipefd[0] != -1)
		close(pipefd[0]);
	if (pipefd[1] != -1)
		close(pipefd[1]);
	exit(status);
}
