/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:20:27 by ade-fran          #+#    #+#             */
/*   Updated: 2023/11/16 12:20:30 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dup;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	dup = malloc((ft_strlen(s) * sizeof(char)) + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = f(i, s[i]);
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
