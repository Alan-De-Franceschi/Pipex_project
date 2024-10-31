/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:36:18 by ade-fran          #+#    #+#             */
/*   Updated: 2024/01/17 14:36:19 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_list(t_list *lst, int fd)
{
	while (lst)
	{
		ft_printf("[%d]->", fd, lst->data);
		lst = lst->next;
	}
	if (!lst)
		ft_printf("[NULL]", fd);
	ft_printf("\n", fd);
}
