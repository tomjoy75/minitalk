/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 01:35:11 by leo               #+#    #+#             */
/*   Updated: 2023/12/04 19:55:17 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_flag;

void	handler_sigusr(int sig)
{
	if (sig == SIGUSR1)
		g_flag = 0;
}

void	send_msg(int pid, char msg, int n)
{
	if (pid <= 1)
		exit_error("Invalid pid\n");
	if (n < 7)
		send_msg(pid, msg >> 1, n + 1);
	g_flag = 1;
	if ((msg % 2))
	{
		if (kill(pid, SIGUSR1) == -1)
			exit_error("Invalid pid\n");
	}
	else if (kill(pid, SIGUSR2) == -1)
		exit_error("Invalid pid");
	while (g_flag)
		;
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	if (ac != 3)
		exit_error("Usage: ./client PID message\n");
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = &handler_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (*av[2])
		send_msg(ft_atoi(av[1]), *av[2]++, 0);
	send_msg(ft_atoi(av[1]), 0, 0);
}
