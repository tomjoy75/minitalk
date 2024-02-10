/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:28:53 by joyeux            #+#    #+#             */
/*   Updated: 2024/02/10 15:51:00 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <libft/libft.h>

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
}

int	main(int argc, char **argv)
{
	if (argc < 3)
		return (1);
/*	while (*argv[1])
	{
		ft_atob(*argv[1]);
		argv[1]++;
	}*/
	if (argv[2][0] == 'a')
		kill(ft_atoi(argv[1]), SIGUSR1);
	if (argv[2][0] == 'b')
		kill(ft_atoi(argv[1]), SIGUSR2);
	return (0);
}