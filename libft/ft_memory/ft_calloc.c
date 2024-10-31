/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:09:04 by ade-fran          #+#    #+#             */
/*   Updated: 2023/11/10 15:09:06 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*m;

	if (nmemb == 0 || size == 0)
	{
		return (malloc(1));
	}
	if (size != 0 && nmemb > ((size_t) - 1) / size)
		return (NULL);
	m = malloc(nmemb * size);
	if (!m)
		return (NULL);
	ft_bzero(m, nmemb * size);
	return ((void *)m);
}
