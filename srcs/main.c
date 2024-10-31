/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:13:31 by ade-fran          #+#    #+#             */
/*   Updated: 2024/03/06 18:13:33 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc < 5)
	{
		ft_printf("pipex: Too few arguments", 2);
		return (1);
	}
	if (argc > 5)
	{
		ft_printf("pipex: Too many arguments", 2);
		return (1);
	}
	ft_init_data(&data, argc, argv, envp);
	ft_exec_cmd(data);
}
