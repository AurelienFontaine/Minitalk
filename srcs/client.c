/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:27:26 by afontain          #+#    #+#             */
/*   Updated: 2023/10/10 13:55:10 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	bit_control;

void	send_char(char c, pid_t pid)
{
	int	bit;

	bit = __CHAR_BIT__ * sizeof(c) - 1;
	while (bit >= 0)
	{
		if (kill(pid, 0) < 0)
		{
			// ft_printf("ERROR : can't send signal to pid : %d\n", pid);
			ft_printf("Erreur : envoie du signal au pid impossible : %d\n", pid);
			exit(EXIT_FAILURE);
		}
		bit_control = 0;
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		while (bit_control != 1)
			usleep(10);
	}
}

void	send_str(char *str, pid_t pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(str[i], pid);
		i++;
	}
	send_char(0, pid);
}

void	sig_usr(int sig)
{
	if (sig == SIGUSR1)
		bit_control = 1;
	else if (sig == SIGUSR2)
	{
		ft_printf("Message bien reçu !\n");
		exit(EXIT_SUCCESS);
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
	{
		ft_printf("Tuto: %s <PID du serveur> <message>\n", av[0]);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, &sig_usr);
	signal(SIGUSR2, &sig_usr);
	pid = ft_atoi(av[1]);
	if (!pid)
	{
		ft_printf("%s Mauvais pid\n", av[1]);
		exit(EXIT_FAILURE);
	}
	send_str(av[2], pid);
	while (1)
		pause();
}
