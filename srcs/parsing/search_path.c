/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:24:06 by ade-fran          #+#    #+#             */
/*   Updated: 2024/03/14 17:24:08 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_make_cmd_path(char *path, char *cmd)
{
	char	*cmd_path;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cmd_path = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(cmd) + 2));
	if (!cmd_path)
		return (NULL);
	while (path[i])
	{
		cmd_path[i] = path[i];
		i++;
	}
	cmd_path[i++] = '/';
	while (cmd[j])
		cmd_path[i++] = cmd[j++];
	cmd_path[i] = '\0';
	return (cmd_path);
}

static int	ft_check_access(char *cmd_path)
{
	if (access(cmd_path, F_OK) == -1)
		return (CMD_ACCESS);
	if (access(cmd_path, F_OK | X_OK) == -1)
		return (PERM_DENIED);
	return (0);
}

char	*ft_search_path(char **paths, char *cmd, int *err)
{
	char	*cmd_path;
	int		i;

	i = 0;
	if (ft_strchr(cmd, '/') != NULL && ft_check_access(cmd) == CMD_ACCESS)
		return (ft_cmd_errors(CMD_ACCESS, cmd, err), NULL);
	if (ft_strchr(cmd, '/') != NULL && ft_check_access(cmd) == PERM_DENIED)
		return (ft_cmd_errors(PERM_DENIED, cmd, err), NULL);
	if (ft_check_access(cmd) == 0)
		return (ft_strdup(cmd));
	while (paths[i])
	{
		cmd_path = ft_make_cmd_path(paths[i], cmd);
		if (!cmd_path)
			return (ft_errors(SEARCH_PATH), NULL);
		if (ft_check_access(cmd_path) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	ft_cmd_errors(CMD_NOT_FOUND, cmd, err);
	return (NULL);
}
