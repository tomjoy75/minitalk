/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyeux <joyeux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:29:41 by joyeux            #+#    #+#             */
/*   Updated: 2024/02/14 00:44:23 by joyeux           ###   ########.fr       */
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
	static int	bit_count = 0;
	static char	c = 0;
	static char	tab[4096];

	(void)ucontext;
	// Cas ou on recoit le signal de fin de mot
	/*if (sig == SIGUSR2 && (bit_count % 8) == 0)
	{
		write (1, tab, bit_count / 8);
		printf("\nShow word : %s \n", tab);
		bit_count = 0;
		return ;
	}*/
	printf("  __ bit %d : ", bit_count);
	// Cas ou in recoit un bit de 1
	if (sig == SIGUSR2)
	{
		c = c | 1 << (7 - (bit_count) % 8);
		printf("1");
	}
	else
		printf("0");
	bit_count++;
	// Cas ou on a recu tous les bits et constitue un octet
	// TODO: extraire le char et l'agreger dans une string
	if (bit_count % 8 == 0)
	{
	//	write(1, &c, 1);
		tab[bit_count / 8 - 1] = c;
	//	printf("%c\n", c);
		printf(" put %c at %d\n", c, bit_count / 8 -1);
		if (c == 0)
		{
			write (1, tab, bit_count / 8);
			printf("\nShow word : %s \n", tab);
			bit_count = 0;
			return ;
		}

	//	bit_count = 0;
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
