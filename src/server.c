/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:02:30 by sarajime          #+#    #+#             */
/*   Updated: 2024/06/06 19:08:04 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int s)
{
	if (s == SIGUSR1)
		write_signal(0);
	else
		write_signal(1);
}

void	write_signal(int s)
{
	static int	bit = 7;
	static int	box = 0;

	box += (s << bit);
	if (bit == 0)
	{
		ft_printf("%c", box);
		bit = 7;
		box = 0;
	}
	else
		bit--;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID = %d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		;
}
