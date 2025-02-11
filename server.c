/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:40:53 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/11 16:47:04 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	action(int sig)
{
	static unsigned char	buffer;
	static int				i;

	i = 0;
	buffer = 0;
	buffer = (buffer << 1) | (sig == SIGUSR1);
	i++;
	if (i == 8)
	{
		write(1, &buffer, 1);
		i = 0;
		buffer = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	while (1)
		pause();
}
