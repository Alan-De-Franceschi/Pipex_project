/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:04:29 by ade-fran          #+#    #+#             */
/*   Updated: 2024/03/14 20:04:31 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_search_path_line(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return (NULL);
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			return (&envp[i][5]);
		i++;
	}
	return (NULL);
}

char	**ft_split_env(char **envp)
{
	char	**paths;
	char	*path_line;

	path_line = ft_search_path_line(envp);
	if (!path_line)
		return (NULL);
	paths = ft_split(path_line, ":");
	if (!paths)
		return (ft_errors(SPLIT_ENV), NULL);
	return (paths);
}
