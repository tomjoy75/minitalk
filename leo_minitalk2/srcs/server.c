/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 01:35:11 by leo               #+#    #+#             */
/*   Updated: 2023/12/04 15:56:42 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_sigusr(int sig, siginfo_t *info, void *ucontext)
{
	static char		byte;
	static size_t	counter;
	static char		buff[SIZE];

	(void)ucontext;
	byte = byte * 2 + (sig == SIGUSR1);
	if ((++counter % 8) == 0)
	{
		buff[counter / 8 - 1] = byte;
		if (!byte || counter / 8 == SIZE)
		{
			write(1, buff, counter / 8);
			counter = 0;
		}
		if (!byte)
			write(1, "\n", 1);
		byte = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("%d\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &handler_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
