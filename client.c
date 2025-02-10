/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:35:58 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/10 14:24:58 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void	send_signals(int pid, char *message)
// {
// 	int				letter;
// 	int				i;

// 	letter = 0;
// 	while (message[letter])
// 	{
// 		i = -1;
// 		while (++i < 8)
// 		{
// 			if (((unsigned char)(message[letter] >> (7 - i)) & 1) == 0)
// 				kill(pid, SIGUSR1);
// 			else if (((unsigned char)(message[letter] >> (7 - i)) & 1) == 1)
				// kill(pid, SIGUSR2);
// 			usleep(50);
// 		}
// 	letter++;
// 	}
// 	i = 0;
// 	while (i++ < 8)
// 	{
// 		kill(pid, SIGUSR1);
// 		usleep(50);
// 	}
// }

int	main(int ac, char **av)
{
	int		pid;
	char	*messag;
	int		letter;
	messag = av[2];
	if (ac != 3)
		return (ft_putendl_fd("Error\nyou enter arguments as follow: ./client <PID> <MESSAGE>", 2), 1);
	pid = ft_atoi(av[1]);
	while (messag[letter])
	{
		int i = 0;
		while (i < 8)
		{
			if (((unsigned char)(messag[letter] >> (7 - i)) & 1) == 0)
				kill(pid, SIGUSR1);
			usleep(50);
			i++;
		}
		letter++;
	}
}
