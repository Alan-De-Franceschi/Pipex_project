/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:06:35 by ade-fran          #+#    #+#             */
/*   Updated: 2024/03/20 17:06:37 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_split_cmd(char *str_cmd, int *err)
{
	char	**cmd;

	cmd = ft_split(str_cmd, " ");
	if (!cmd)
	{
		*err = CMD_NOT_FOUND;
		return (ft_cmd_errors(CMD_NOT_FOUND, str_cmd, err), NULL);
	}
	return (cmd);
}
