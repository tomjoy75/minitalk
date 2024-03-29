/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:29:41 by joyeux            #+#    #+#             */
/*   Updated: 2024/02/12 16:49:04 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
//#include <sys/types.h>
//#include <stdio.h>
#include <signal.h>
#include "libft/libft.h"

void	handle_sigusr(int sig, siginfo_t *info, void *ucontext)
{
	static int	bit_count = 0;
	static short	c = 0;

	(void)ucontext;
	if (sig == SIGUSR2 && !bit_count)
	{
		write (1, "\n", 1);
		kill(info->si_pid, SIGUSR2);
		return ;
	}
	if (sig == SIGUSR2)
		c = c | 1 << (31 - bit_count);
	bit_count++;
	if (bit_count == 32)
	{
		write(1, &c, 1);
		bit_count = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				process_id;
	struct sigaction	sa;

	sa.sa_sigaction = &handle_sigusr;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	process_id = getpid();
	ft_putstr_fd("\t\tServer PID : [\e[5m", 1);
	ft_putnbr_fd(process_id, 1);
	ft_putstr_fd("\e[0m]\n\n\t\t---RECEPTION SPACE---\n", 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
