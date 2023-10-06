/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:20:44 by afontain          #+#    #+#             */
/*   Updated: 2023/10/05 12:44:42 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	b_control;

void	handle_char(char c, int pid)
{
	int bit;
	
	bit = __CHAR_BIT__*sizeof(c) - 1;
	while (bit >= 0)
	{
		if (kill(pid, 0) < 0)
		{
			ft_printf("Error : %i\n", pid);
			exit(EXIT_FAILURE);
		}
		if (c & 1<<bit)
			kill(pid, SIGUSR1);
		else	
			kill(pid, SIGUSR2);
		while (b_control != 1)
			usleep(10);
		bit--;
	}
}

void	handle_sig(char *str, int pid)
{
	int	i;

	i = 0;
	while(str[i])
	{
		handle_char(str[i], pid);
		i++;
	}
	handle_char(0, pid);
}

void	sig_usr(int sig)
{
	if (sig == SIGUSR1)
		b_control = 1;
	else if (sig == SIGUSR2)
	{
		ft_printf("Msg delivered !\n");
		exit(EXIT_SUCCESS);
	}
}

int main(int ac, char **av)
{
	pid_t	pid;
	
	// pid = fork();
	if (ac != 3)
	{
		ft_printf("Only 2 parameters");
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, sig_usr);
	signal(SIGUSR2, sig_usr);
	pid = ft_atoi(av[1]);
	if (!pid)
		ft_printf("Error bad pid\n %s", av[1]);
	handle_sig(av[2], pid);
	while (1)
		sleep(10);
	return (0);
}
