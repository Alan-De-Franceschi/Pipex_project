/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:17:27 by ade-fran          #+#    #+#             */
/*   Updated: 2023/11/10 11:17:31 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*a;
	const unsigned char	*b;

	i = 0;
	a = dest;
	b = src;
	if (!(dest) && !(src) && n != 0)
		return (NULL);
	if (a < b)
	{
		while (i < n)
		{
			a[i] = b[i];
			i++;
		}
	}
	else
	{
		while (n--)
		{
			a[n] = b[n];
		}
	}
	return ((void *)dest);
}
