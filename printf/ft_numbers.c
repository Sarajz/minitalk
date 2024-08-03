/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:11:47 by sarajime          #+#    #+#             */
/*   Updated: 2023/12/26 14:51:29 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digit(int num)
{
	int	count;

	count = 0;
	if (num != 0)
	{
		if (num == -2147483648)
			return (11);
		if (num < 0)
		{
			count++;
			num *= -1;
		}
		while (num > 0)
		{
			num = num / 10;
			count++;
		}
	}
	else
		count = 1;
	return (count);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	digit;

	digit = 0;
	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	else if (n < 0)
	{
		write (fd, "-", 1);
		n = -n;
	}
	if (n < 10 && n >= 0)
		ft_putchar (n + '0');
	if (n >= 10)
	{
		digit = n % 10;
		n = n / 10;
		ft_putnbr_fd(n, fd);
		ft_putchar(digit + '0');
	}
}

int	ft_putnbr(int n)
{
	ft_putnbr_fd(n, 1);
	return (ft_count_digit(n));
}

int	ft_puthexa(unsigned long long n, char c)
{
	char	*str;
	int		len;

	str = "0123456789abcdef";
	if (c == 'X')
		str = "0123456789ABCDEF";
	len = 0;
	if (n < 16)
		return (ft_putchar(str[n]));
	else
	{
		len += ft_puthexa(n / 16, c);
		len += ft_puthexa(n % 16, c);
	}
	return (len);
}
