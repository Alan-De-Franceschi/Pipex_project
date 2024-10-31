/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:57:48 by ade-fran          #+#    #+#             */
/*   Updated: 2023/11/28 17:57:51 by ade-fran         ###   ########.fr       */
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

static int	display_ptr(uintptr_t ptr, char *base, int fd)
{
	uintptr_t	size;
	uintptr_t	address;
	int			count;

	size = ft_strlen(base);
	address = ptr;
	count = 0;
	if (check_base(base))
	{
		if (address < size)
			ft_putchar_fd(base[address % size], fd);
		if (address >= size)
		{
			count = display_ptr(address / size, base, fd);
			ft_putchar_fd(base[address % size], fd);
		}
	}
	return (count + 1);
}

int	ft_putptr(uintptr_t ptr, char *base, int fd)
{
	int	count;

	count = 0;
	if (!ptr)
		count = ft_putstr_fd("(nil)", fd);
	else
	{
		count = ft_putstr_fd("0x", fd);
		count += display_ptr(ptr, base, fd);
	}
	return (count);
}
