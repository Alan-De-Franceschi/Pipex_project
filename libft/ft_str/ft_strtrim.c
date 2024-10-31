/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:56:21 by ade-fran          #+#    #+#             */
/*   Updated: 2023/11/15 14:56:24 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set_char(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	str_size(int b, int e)
{
	int		size;

	if (e >= b)
		size = e - b + 1;
	else
		size = 0;
	return (size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*m;
	int		i;
	int		b;
	int		e;
	int		size;

	i = 0;
	b = 0;
	if (!s1)
		return (NULL);
	e = ft_strlen(s1) - 1;
	while (is_set_char(s1[b], set) == 1)
		b++;
	while (is_set_char(s1[e], set) == 1 && e >= 0)
		e--;
	size = str_size(b, e);
	m = (char *)malloc(size * sizeof(char) + 1);
	if (!m)
		return (NULL);
	while (b <= e)
		m[i++] = s1[b++];
	m[i] = '\0';
	return (m);
}
