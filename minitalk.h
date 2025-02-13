/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:29:53 by ybounite          #+#    #+#             */
/*   Updated: 2025/02/12 14:48:38 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>

# define YELLOW	"\e[1;33m"
# define RED     "\e[1;31m"
# define GREEN   "\e[1;32m"
# define BLUE    "\e[1;34m"
# define WHITE   "\e[1;37m"

void	send_char(int pid, unsigned char c);
void	action(int sig);
#endif