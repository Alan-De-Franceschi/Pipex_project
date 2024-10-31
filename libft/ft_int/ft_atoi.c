/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:07:25 by ade-fran          #+#    #+#             */
/*   Updated: 2023/11/10 14:07:28 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr, int *error)
{
	int			i;
	int			s;
	long int	num;

	i = 0;
	s = 1;
	num = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if ((nptr[i] == '-' || nptr[i] == '+') && nptr[i + 1])
	{
		if (nptr[i] == '-')
			s = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		if ((s == 1 && num > INT_MAX) || (s == -1 && num * s < INT_MIN))
			*error = 1;
		i++;
	}
	if (nptr[i])
		*error = 1;
	return (num * s);
}
