/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_inter_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:06:45 by ade-fran          #+#    #+#             */
/*   Updated: 2024/03/25 16:06:46 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_inter_file(int pipefd[2])
{
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		return (ft_errors(DUP_ERR), 0);
	close(pipefd[0]);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		return (ft_errors(DUP_ERR), 0);
	close(pipefd[1]);
	return (1);
}
