/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:45:24 by eedwards          #+#    #+#             */
/*   Updated: 2024/09/12 13:42:09 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200112L
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>

int	g_received_signal = 0;

static void	signal_handler(int sig)
{
	(void) sig;
	g_received_signal = 1;
}

//Encrypt the message (I did the encryption via bits)
//Send the message to the server (via its PID)
//Create a stop condition so that the server knows when it has finished
// 	receiving the message
static void	send(pid_t pid, char *message)
{
	int					shift;
	int					i;
	struct sigaction	sa;

	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	i = 0;
	while (message[i])
	{
		shift = 7;
		while (shift >= 0)
		{
			if (((message[i] >> shift) & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (!g_received_signal)
				pause();
			g_received_signal = 0;
			shift--;
		}
		i++;
	}
	exit (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*message;

	if (ac != 3)
	{
		perror("Wrong input\n");
		perror("Example of correct input: ./client <pid> <string>\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		perror("Invalid PID");
		return (1);
	}
	message = av[2];
	send(pid, message);
}
