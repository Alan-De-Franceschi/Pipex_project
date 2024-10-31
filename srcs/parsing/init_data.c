/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:09:59 by ade-fran          #+#    #+#             */
/*   Updated: 2024/03/21 16:10:01 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_data(t_data *data, int argc, char **argv, char **envp)
{
	data->ac = argc;
	data->av = argv;
	data->envp = envp;
	data->paths = NULL;
	if (if_heredoc(argv[1]) && argc >= 6)
	{
		data->nb_cmd = argc - 4;
		data->index_cmd = argc - 4;
		data->if_heredoc = 1;
		ft_get_heredoc(argv[2], data->heredoc, 0);
	}
	else
	{
		data->nb_cmd = argc - 3;
		data->index_cmd = argc - 3;
		data->if_heredoc = 0;
		data->heredoc[0] = -1;
		data->heredoc[1] = -1;
	}
	return ;
}
