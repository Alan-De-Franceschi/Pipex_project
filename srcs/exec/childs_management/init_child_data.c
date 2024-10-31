/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_child_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:09:06 by ade-fran          #+#    #+#             */
/*   Updated: 2024/03/24 14:09:08 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_child_data(t_child *child_data)
{
	child_data->cmd = NULL;
	child_data->path = NULL;
	child_data->infile = -1;
	child_data->outfile = -1;
}
