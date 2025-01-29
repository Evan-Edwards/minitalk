/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:45:24 by eedwards          #+#    #+#             */
/*   Updated: 2024/09/26 17:35:34 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>

int	g_signal_received = 0;

static void	signal_handler(int signum)
{
	(void)signum;
	g_signal_received = 1;
}

//sends signal to server
static void	send_sig(pid_t pid, int signum)
{
	if (kill(pid, signum) == -1)
	{
		ft_putstr_fd("Error sending signal\n", 2);
		exit(EXIT_FAILURE);
	}
}

// Function to wait for the server's acknowledgment
// If after 100 ms there is no acknowledgment returns 0
static int	wait_for_ack(void)
{
	int	timeout;

	timeout = 1000;
	while (!g_signal_received && timeout > 0)
	{
		usleep(100);
		timeout--;
	}
	return (timeout > 0);
}

// Sends a single character to the server by breaking it into bits
// Each bit is sent as a signal: SIGUSR1 for 1, SIGUSR2 for 0
// Exits the program if there's an error sending the signal
static void	send_char(pid_t pid, char c)
{
	int	bit;

	bit = 8;
	while (bit-- > 0)
	{
		g_signal_received = 0;
		if (c & (1 << bit))
			send_sig(pid, SIGUSR1);
		else
			send_sig(pid, SIGUSR2);
		if (!wait_for_ack())
		{
			ft_putstr_fd("Timeout waiting for server acknowledgment\n", 2);
			exit(EXIT_FAILURE);
		}
	}
}

//Sends a string to the server by calling send_char for each character
//and then sending a null character to indicate the end of the string
int	main(int ac, char **av)
{
	pid_t	pid;
	char	*message;

	if (ac != 3 || av[2] == NULL || *av[2] == '\0')
	{
		ft_putstr_fd("Wrong input\n", 2);
		ft_putstr_fd("Example of correct input: ./client <pid> <string>\n", 2);
		return (1);
	}
	signal(SIGUSR1, signal_handler);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_putstr_fd("Invalid PID\n", 2);
		return (1);
	}
	message = av[2];
	while (*message)
	{
		send_char(pid, *message);
		message++;
	}
	send_char(pid, '\0');
}
