/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:40:53 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/12 14:53:27 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	action(int sig)
{
	static unsigned char	buff = 0;
	static int				i = 0;

	buff = (buff << 1) | (sig == SIGUSR1);
	i++;
	if (i == 8)
	{
		write(1, &buff, 1);
		i = 0;
		buff = 0;
		kill(getppid(), SIGUSR1);
	}
	
}

int	main(void)
{
	ft_printf("%sServer PID: %s%d\n", GREEN, WHITE, getpid());
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	while (1)
		pause();
}
