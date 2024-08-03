/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:07:21 by sarajime          #+#    #+#             */
/*   Updated: 2024/06/06 19:08:26 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include "../printf/ft_printf.h"

void	write_signal(int s);
void	handler(int s);
void	send_signal(int pid, char *str);
int		ft_atoi(const char *str);

#endif