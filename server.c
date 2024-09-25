/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:50:21 by eedwards          #+#    #+#             */
/*   Updated: 2024/09/25 10:47:18 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200112L //??
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include "libft.h"

// This function handles incoming signals (SIGUSR1 and SIGUSR2) from clients
// It reconstructs characters bit by bit and prints them
// It ensures that a complete message from one client is received before 
// processing signals from another
static void	handle_signal(int signal, siginfo_t *info, void *unused_context)
{
	static int		i = 0;
	static char		c = 0;
	static pid_t	current_client = 0;

	(void) unused_context;
	if (current_client == 0 || current_client == info->si_pid)
	{
		current_client = info->si_pid;
		if (signal == SIGUSR1)
			c |= 1 << (7 - i);
		i++;
		if (i == 8)
		{
			if (c == '\0')
			{
				ft_putchar('\n');
				current_client = 0;
			}
			else
				ft_putchar(c);
			c = 0;
			i = 0;
		}
	}
}

//first prints PID, then every time SIGUSR1 or SIGUSR2 are received it calls
//the handle_signal function. It pauses in between signals
int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("Server PID is: %d\n", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_putstr_fd("Error installing signal handler for SIGUSR1\n", 2);
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putstr_fd("Error installing signal handler for SIGUSR2\n", 2);
		return (1);
	}
	while (1)
	{
		pause();
	}
	return (0);
}
