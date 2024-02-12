/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyeux <joyeux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:28:53 by joyeux            #+#    #+#             */
/*   Updated: 2024/02/12 01:09:56 by joyeux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <libft/libft.h>

int	cont;
/*
void	ft_atob(char c)
{
	char	tab[8];
	int		i;

	i = 8;
	while (--i >= 0)
	{
		tab[i] = (c >> i & 1) + 48;
		write (1, &tab[i], 1);
	}
	write (1, "\n", 1);
}*/
void sigusr1_handler(int sig)
{
	(void)sig;
	cont = 1;
}

int	main(int argc, char **argv)
{
	int	i;
	char	tab[8];
	struct sigaction	sa;
	{
		/* data */
	};


	if (argc < 3)
		return (1);
//	TODO: check argv[1] is PID format
	sa.sa_handler = sigusr1_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	i = 8;
	while (*argv[2])
	{
		while (--i >= 0)
		{
			cont = 0;
			tab[i] = (*argv[2] >> i & 1) + 48;
			write (1, &tab[i], 1);
			if (tab[i] == '0')
				kill(ft_atoi(argv[1]), SIGUSR1);
			else if (tab[i] == '1')
				kill(ft_atoi(argv[1]), SIGUSR2);
			while (!cont)
				pause();
		}
		i = 8;
		argv[2]++;
		write (1, "\n", 1);
	}
	kill(ft_atoi(argv[1]), SIGUSR2);
	/*
	if (argv[2][0] == 'a')
		kill(ft_atoi(argv[1]), SIGUSR1);
	if (argv[2][0] == 'b')
		kill(ft_atoi(argv[1]), SIGUSR2);
	return (0);*/
}