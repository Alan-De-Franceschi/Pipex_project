/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:14:47 by ade-fran          #+#    #+#             */
/*   Updated: 2023/11/27 20:14:49 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		if (!(ft_isprint(base[i])))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base_fd(unsigned int n, char *base, int fd)
{
	unsigned int	size;
	unsigned int	num;
	int				count;

	size = ft_strlen(base);
	num = n;
	count = 0;
	if (check_base(base))
	{
		if (num < size)
			ft_putchar_fd(base[num % size], fd);
		if (num >= size)
		{
			count = ft_putnbr_base_fd(num / size, base, fd);
			ft_putchar_fd(base[num % size], fd);
		}
	}
	return (count + 1);
}
