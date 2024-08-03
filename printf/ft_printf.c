/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:11:18 by sarajime          #+#    #+#             */
/*   Updated: 2023/12/28 17:10:37 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char c, va_list arg)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthexa((va_arg(arg, unsigned int)), c));
	else if (c == 'p')
		return (ft_putstr("0x")
			+ ft_puthexa((va_arg(arg, unsigned long long)), c));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(arg, unsigned int)));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(arg, str);
	if (write(1, "", 0) == -1)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_check(str[i], arg);
		}
		else
		{
			len += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(arg);
	return (len);
}
