/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:02:30 by sarajime          #+#    #+#             */
/*   Updated: 2024/06/06 18:50:18 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	write_signal(int s, pid_t pid)
{
	static int	bit = 7;
	static int	box = 0;

	box += (s << bit);
	if (bit == 0)
	{
		if (box != 0)
		{
			ft_printf("%c", box);
			bit = 7;
			box = 0;
		}
		else
		{
			kill(pid, SIGUSR1);
			write (1, "\n", 1);
			bit = 7;
		}
	}
	else
		bit--;
}

void	handler(int s, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (s == SIGUSR1)
		write_signal(0, info->si_pid);
	else
		write_signal(1, info->si_pid);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	pid = getpid();
	ft_printf("PID = %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
}
