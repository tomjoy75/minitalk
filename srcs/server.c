/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyeux <joyeux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:29:41 by joyeux            #+#    #+#             */
/*   Updated: 2024/02/09 16:12:33 by joyeux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
//#include <stdio.h>
#include "libft/libft.h"

int	main(void)
{
	pid_t	process_id;

	process_id = getpid();
//	printf ("PID : %d\n", process_id);
	ft_putnbr_fd(process_id, 1);
	return (0);
}