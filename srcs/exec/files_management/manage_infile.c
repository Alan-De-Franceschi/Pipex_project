/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_infile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:30:03 by ade-fran          #+#    #+#             */
/*   Updated: 2024/03/25 14:30:05 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_manage_infile(t_child *c_data, char *file, int pipefd[2])
{
	if (access(file, F_OK | R_OK) == -1)
		return (ft_file_errors(file), 0);
	c_data->infile = open(file, O_RDONLY);
	if (c_data->infile == -1)
		return (ft_file_errors(file), 0);
	if (dup2(c_data->infile, STDIN_FILENO) == -1)
		return (ft_errors(DUP_ERR), 0);
	close(c_data->infile);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		return (ft_errors(DUP_ERR), 0);
	close(pipefd[1]);
	return (1);
}
