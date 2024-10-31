/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:13:59 by ade-fran          #+#    #+#             */
/*   Updated: 2023/11/14 14:14:01 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_size(int n)
{
	int			count;
	long int	num;

	count = 0;
	num = n;
	if (num <= 0)
	{
		num *= (-1);
		count++;
	}
	while (num)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	ft_putnbr_fd(int n, int fd)
{
	long int	i;
	char		a;
	char		b;

	i = n;
	a = '0';
	b = '0';
	if (i < 0)
	{
		write(fd, "-", 1);
		i = i * (-1);
	}
	if (i <= 9)
	{
		a = a + i;
		write(fd, &a, 1);
	}
	if (i >= 10)
	{
		ft_putnbr_fd(i / 10, fd);
		b = b + (i % 10);
		write(fd, &b, 1);
	}
	return (nbr_size(n));
}
