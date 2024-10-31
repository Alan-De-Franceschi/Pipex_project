/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:26:40 by ade-fran          #+#    #+#             */
/*   Updated: 2023/11/23 14:26:43 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_display_args(const char *fmt, int fd, va_list args)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (*fmt == 'd' || *fmt == 'i')
		count += ft_putnbr_fd(va_arg(args, int), fd);
	if (*fmt == 'u')
		count += ft_putnbr_base_fd(va_arg(args, int), "0123456789", fd);
	if (*fmt == 'x')
		count += ft_putnbr_base_fd(va_arg(args, int), base, fd);
	if (*fmt == 'X')
		count += ft_putnbr_base_fd(va_arg(args, int), "0123456789ABCDEF", fd);
	if (*fmt == 'p')
		count += ft_putptr((uintptr_t)va_arg(args, void *), base, fd);
	if (*fmt == 'c')
		count += ft_putchar_fd(va_arg(args, int), fd);
	if (*fmt == '%')
		count += ft_putchar_fd(*fmt, fd);
	if (*fmt == 's')
		count += ft_putstr_fd((char *)va_arg(args, char *), fd);
	return (count);
}

int	ft_printf(const char *fmt, int fd, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (!fmt)
		return (-1);
	va_start(args, fd);
	while (*fmt)
	{
		while (*fmt && *fmt != '%')
		{
			ft_putchar_fd(*fmt++, fd);
			count++;
		}
		if (*fmt == '%')
		{
			fmt++;
			count += ft_display_args(fmt, fd, args);
			fmt++;
		}
	}
	va_end(args);
	return (count);
}
