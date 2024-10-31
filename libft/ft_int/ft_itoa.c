/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:53:02 by ade-fran          #+#    #+#             */
/*   Updated: 2023/11/15 11:53:06 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_nbr(int n)
{
	int			i;
	long int	num;

	i = 0;
	num = n;
	if (num <= 0)
	{
		num *= (-1);
		i++;
	}
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*s;
	int			i;
	int			count;
	long int	num;

	i = 0;
	count = size_nbr(n);
	num = n;
	s = (char *)malloc(count * sizeof(char) + 1);
	if (!s)
		return (NULL);
	if (num < 0)
	{
		num *= (-1);
		s[0] = '-';
		i++;
	}
	s[count] = '\0';
	while (count > i)
	{
		count--;
		s[count] = num % 10 + '0';
		num /= 10;
	}
	return (s);
}
