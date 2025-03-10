/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:50:12 by ybounite          #+#    #+#             */
/*   Updated: 2025/02/17 16:14:51 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_bit(pid_t pid, int sig)
{
	if (sig == 1)
		sig = SIGUSR1;
	else
		sig = SIGUSR2;
	if (kill(pid, sig) == -1)
	{
		ft_printf("%sError sending signal", RED);
		exit(1);
	}
}

void	ft_send_char(pid_t pid, char c)
{
	int (i);
	i = 0;
	while (i < 8)
	{
		ft_send_bit(pid, (c >> (7 - i)) & 1);
		usleep(500);
		i++;
	}
}

void	ft_send_string(pid_t pid, char *str)
{
	int (i);
	i = 0;
	while (str[i])
	{
		ft_send_char(pid, str[i]);
		i++;
	}
	ft_send_char(pid, '\0');
}

int	main(int ac, char **av)
{
	pid_t (pid);
	if (ac != 3)
		return (ft_printf("Usage:%s%s <PID> <Message>\n", RED, av[0]), 1);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		return (ft_printf("%sInvalid PID\n", RED), 1);
	ft_send_string(pid, av[2]);
	return (0);
}
