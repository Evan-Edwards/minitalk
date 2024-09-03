/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:50:21 by eedwards          #+#    #+#             */
/*   Updated: 2024/09/03 16:44:18 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //remove
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include "libft/libft.h"

//#Display its PID 
//Create an endless loop so that the server can receive signals at any time
//Receive signals

//Decrypt signals
//For each signal received (SIGUSR1 & SIGUSR2) it should take a certain action

int	main()
{
	printf("Server PID is: %d\n", getpid());
	while (1)
	{
		
	}
}