/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelfirst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:39:02 by ade-fran          #+#    #+#             */
/*   Updated: 2024/01/17 14:39:04 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelfirst(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	temp = (*lst)->next;
	ft_lstdelone(*lst);
	*lst = temp;
}
