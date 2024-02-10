/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:29:41 by joyeux            #+#    #+#             */
/*   Updated: 2024/02/10 17:09:55 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include "libft/libft.h"

void	handle_sigusr(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (sig == SIGUSR1)
		printf("\nSIGUSR1 intercepted \n");	
	else if (sig == SIGUSR2)
		printf("\nSIGUSR2 intercepted \n");
	printf("from process: %d\n", info->si_pid);
		
}

int	main(void)
{
	pid_t	process_id;
	struct	sigaction sa;

	sa.sa_sigaction = &handle_sigusr;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	process_id = getpid();
//	printf ("PID : %d\n", process_id);
	ft_putnbr_fd(process_id, 1);
	while (1)
		pause();
	return (0);
}