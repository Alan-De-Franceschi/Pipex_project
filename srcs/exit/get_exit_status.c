/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exit_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:03:31 by ade-fran          #+#    #+#             */
/*   Updated: 2024/03/27 15:03:34 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_get_exit_status(int pid)
{
	int	child_status;
	int	wait_status;
	int	exit_status;

	wait_status = 0;
	exit_status = 1;
	while (wait_status != -1)
	{
		wait_status = wait(&child_status);
		if (wait_status == pid)
		{
			if (WIFEXITED(child_status))
				exit_status = WEXITSTATUS(child_status);
			else
				exit_status = EXIT_SUCCESS;
		}
	}
	return (exit_status);
}
