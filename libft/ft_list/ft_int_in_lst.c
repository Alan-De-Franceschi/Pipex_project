/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_in_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:17:23 by ade-fran          #+#    #+#             */
/*   Updated: 2024/02/29 12:17:25 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_in_lst(t_list *lst, int n)
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		if (n == temp->data)
			return (1);
		temp = temp->next;
	}
	return (0);
}
