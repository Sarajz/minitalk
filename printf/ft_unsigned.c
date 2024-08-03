/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:35:27 by sarajime          #+#    #+#             */
/*   Updated: 2024/05/24 18:00:59 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digit(unsigned int num)
{
	unsigned int	count;

	count = 0;
	if (num != 0)
	{
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

void	ft_putnbr_u(unsigned int n)
{
	unsigned int	digit;

	digit = 0;
	if (n < 10)
		ft_putchar (n + '0');
	if (n >= 10)
	{
		digit = n % 10;
		n = n / 10;
		ft_putnbr_u(n);
		ft_putchar(digit + '0');
	}
}

int	ft_putnbr_unsigned(unsigned int n)
{
	ft_putnbr_u(n);
	return (ft_count_digit(n));
}
