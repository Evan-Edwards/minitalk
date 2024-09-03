/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:45:24 by eedwards          #+#    #+#             */
/*   Updated: 2024/09/03 16:44:13 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include "libft/libft.h"
//Write a program (main) in which the client takes two parameters/arguments
//	The PID of the server to which it wants to send the message
//	A message

//Encrypt the message (I did the encryption via bits)
//Send the message to the server (via its PID)
//Create a stop condition so that the server knows when it has finished
// 	receiving the message
int	main(int ac, char **av)
{
	int		i;
	int		shift;
	pid_t	pid;
	char	*message;

	if (ac != 3)
		perror("wrong input");
	pid = ft_atoi(av[1]);
	message = av[2];
	i = 0;
	if (ac != 3)
		perror("wrong input"); //TODO
	while (message[i])
	{
		shift = 0; //reverse?
		while (shift < 8)
		{
			if (((message[i] >> shift) & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			upause(300); //why this amount of time?
			shift++;
		}
		i++;
	}
	if (kill(pid, SIGUSR1) == -1) //do I need to check for this?
		//error

}
//check for right inputs and argc