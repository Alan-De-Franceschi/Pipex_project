/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:52:24 by ade-fran          #+#    #+#             */
/*   Updated: 2024/03/04 12:52:27 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsort(t_list *lst)
{
	int		int_temp;
	t_list	*tmp;

	tmp = lst;
	while (lst->next)
	{
		if (lst->data > lst->next->data)
		{
			int_temp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = int_temp;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}
