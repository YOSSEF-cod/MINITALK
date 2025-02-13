/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:35:58 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/12 14:59:51 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, unsigned char c)
{
	int	i = 7;

	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		i--;
	}
}
int	main(int ac, char **av)
{
	int		pid;
	char	*messag;
	int		i;


	if (ac != 3)
		return (ft_printf("%sError\n%s./client <PID> <MESSAGE>", RED, WHITE), 1);
	pid = ft_atoi(av[1]);
	if (pid == -1 || pid == 0)
		return (ft_printf("%sError", RED), 1);
	messag = av[2];
	i = 0;
	while (messag[i])
	{
		send_char(pid, (unsigned char)messag[i]);
		i++;
	}
	send_char(pid, '\0');
	return (0);
}
