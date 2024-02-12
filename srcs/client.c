/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:28:53 by joyeux            #+#    #+#             */
/*   Updated: 2024/02/12 14:08:29 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <libft/libft.h>

int	g_cont;

void	error_message(int i)
{
	if (i == 1)
		ft_printf("Error : Wrong format, please insert like this :\n\t\t"
			"./client <PID> message\n\n");
	else if (i == 2)
		ft_printf("Error : PID Invalid :\n\t\t<PID> contains only numbers\n\n");
	exit(1);
}

int	isnumber(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	sigusr1_handler(int sig)
{
	(void)sig;
	g_cont = 1;
}

void	send_signals(char *pid, char *str)
{
	int		i;
	char	bit;

	i = 8;
	while (*str)
	{
		while (--i >= 0)
		{
			g_cont = 0;
			bit = (*str >> i & 1) + 48;
			if (bit == '0')
				kill(ft_atoi(pid), SIGUSR1);
			else if (bit == '1')
				kill(ft_atoi(pid), SIGUSR2);
			while (!g_cont)
				pause();
		}
		i = 8;
		str++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc < 3)
		error_message(1);
	if (!isnumber(argv[1]))
		error_message(2);
	sa.sa_handler = sigusr1_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	send_signals(argv[1], argv[2]);
	kill(ft_atoi(argv[1]), SIGUSR2);
}
