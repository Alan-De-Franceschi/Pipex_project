/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:44:29 by ade-fran          #+#    #+#             */
/*   Updated: 2023/11/14 15:44:31 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*m;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		m = (char *)malloc(1 * sizeof(char));
		if (!m)
			return (NULL);
		m[0] = 0;
		return (m);
	}
	if (len > ft_strlen(s) - start)
		m = (char *)malloc(((ft_strlen(s) - start) * sizeof(char)) + 1);
	else
		m = (char *)malloc(len * sizeof(char) + 1);
	if (!m)
		return (NULL);
	while (s[start] && i < len)
		m[i++] = s[start++];
	m[i] = '\0';
	return (m);
}
