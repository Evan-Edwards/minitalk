/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:45:24 by eedwards          #+#    #+#             */
/*   Updated: 2024/09/25 10:47:01 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200112L //?
#include <unistd.h>
#include "libft.h"
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>

// Sends a single character to the server by breaking it into bits
// Each bit is sent as a signal: SIGUSR1 for 1, SIGUSR2 for 0
// Exits the program if there's an error sending the signal
static void	send_char(pid_t pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (c & (1 << bit))
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr_fd("Error sending signal\n", 2);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr_fd("Error sending signal\n", 2);
				exit(EXIT_FAILURE);
			}
		}
		usleep(100);
		bit--;
	}
}

//Sends a string to the server by calling send_char for each character
//and then sending a null character to indicate the end of the string
int	main(int ac, char **av)
{
	pid_t	pid;
	char	*message;

	if (ac != 3)
	{
		ft_putstr_fd("Wrong input\n", 2);
		ft_putstr_fd("Example of correct input: ./client <pid> <string>\n", 2);
		return (1);
	}
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
