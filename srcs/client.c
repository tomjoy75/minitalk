/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyeux <joyeux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:28:53 by joyeux            #+#    #+#             */
/*   Updated: 2024/02/09 23:26:23 by joyeux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
	if (argc < 2)
		return (1);
	while (*argv[1])
	{
		ft_atob(*argv[1]);
		argv[1]++;
	}
	return (0);
}