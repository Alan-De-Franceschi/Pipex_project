/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:43:24 by ade-fran          #+#    #+#             */
/*   Updated: 2023/11/15 11:43:30 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*m;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	m = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!m)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			m[i] = s1[i];
			i++;
		}
	}
	if (s2)
	{
		while (s2[j])
			m[i++] = s2[j++];
	}
	m[i] = '\0';
	return (free(s1), m);
}
