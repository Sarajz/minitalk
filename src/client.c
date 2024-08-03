/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:34:50 by sarajime          #+#    #+#             */
/*   Updated: 2024/05/22 19:21:35 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, char *str)
{
	int				i;
	int				j;
	unsigned char	c;

	i = 0;
	while (str[i])
	{
		j = 7;
		c = str[i];
		while (j >= 0)
		{
			if ((c >> j) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(50);
			j--;
		}
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	j = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			j = -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + str[i] - '0';
		i++;
	}
	return (result * j);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		printf("Invalid num argc");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Invalid PID");
		return (0);
	}
	send_signal(pid, argv[2]);
	return (0);
}