/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:50:21 by eedwards          #+#    #+#             */
/*   Updated: 2024/09/12 13:34:37 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200112L //??
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include "libft.h"

//takes in the signal, if the signal is SIGUSR1 it sets the bit to 1 and 
//if it's SIGUSR2 it sets it to 0. Once 8 bits have been set it prints
//char and starts on the next char
static void	handle_signal(int signal, siginfo_t *info, void *unused_context)
{
	static int		i = 0;
	static char		c = 0;
	static pid_t	origin = 0;

	(void) unused_context;
	if (origin == 0)
		origin = info->si_pid;
	if (signal == SIGUSR1)
		c |= 1 << (7 - i);
	i++;
	if (i == 8)
	{
		ft_putchar(c);
		c = 0;
		i = 0;
	}
	if (info->si_pid == origin)
		kill(info->si_pid, SIGUSR1);
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
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
