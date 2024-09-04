/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:50:21 by eedwards          #+#    #+#             */
/*   Updated: 2024/09/04 17:14:36 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //remove
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <zconf.h>//?
#include "libft.h"

//#Display its PID 
//Create an endless loop so that the server can receive signals at any time
//Receive signals

//Decrypt signals
//For each signal received (SIGUSR1 & SIGUSR2) it should take a certain action

void	handle_signal(int signal)
{
	static int	i = 0;
	static int	bit = 0;
	static char	c = 0;
	
	c |= (signal == SIGUSR1)
	while 
	if (signal == SIGUSR1)
		c 
		//bit is 1
	else
		//bit is 0
}
//need some way to store the value and the bit

int	main()
{
	
	printf("Server PID is: %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
	{
		signal(SIGUSR1, handle_signal);
	}
}