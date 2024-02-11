/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:28:53 by joyeux            #+#    #+#             */
/*   Updated: 2024/02/11 17:42:34 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <libft/libft.h>

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

	i = 8;
	while (*argv[2])
	{
		while (--i >= 0)
		{
			tab[i] = (*argv[2] >> i & 1) + 48;
			write (1, &tab[i], 1);
			if (tab[i] == '0')
				kill(ft_atoi(argv[1]), SIGUSR1);
			else if (tab[i] == '1')
				kill(ft_atoi(argv[1]), SIGUSR2);
			sleep(1);
		}
		i = 8;
		argv[2]++;
		write (1, "\n", 1);
	}
	/*
	if (argv[2][0] == 'a')
		kill(ft_atoi(argv[1]), SIGUSR1);
	if (argv[2][0] == 'b')
		kill(ft_atoi(argv[1]), SIGUSR2);
	return (0);*/
}