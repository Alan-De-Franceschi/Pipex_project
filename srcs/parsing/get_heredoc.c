/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:24:36 by ade-fran          #+#    #+#             */
/*   Updated: 2024/03/28 18:24:38 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_check_limiter(char *limiter, char *buf)
{
	int	size;

	size = ft_strlen(limiter);
	if (ft_strncmp(limiter, buf, size) == 0 && buf[size] == '\n')
		return (1);
	return (0);
}

static void	ft_ctrl_d_warning(int fd, char *lim)
{
	close(fd);
	ft_printf("\n%s%s')\n", 2, HD, lim);
	return ;
}

static void	ft_gnl_memory_err(int heredoc[2])
{
	if (errno == ENOMEM)
	{
		ft_errors(GNL_ERR);
		ft_close_pipe(heredoc);
		exit(1);
	}
}

void	ft_get_heredoc(char *limiter, int heredoc[2], int fd)
{
	char	*buf;

	if (pipe(heredoc) == -1)
	{
		ft_errors(PIPE_ERR);
		exit(1);
	}
	while (1)
	{
		buf = ft_get_next_line(fd);
		if (!buf)
		{
			ft_gnl_memory_err(heredoc);
			return (ft_ctrl_d_warning(heredoc[1], limiter));
		}
		if (ft_check_limiter(limiter, buf))
			break ;
		ft_putstr_fd(buf, heredoc[1]);
		free(buf);
	}
	free(buf);
	close(heredoc[1]);
}
