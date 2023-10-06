/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:27:26 by afontain          #+#    #+#             */
/*   Updated: 2023/10/06 13:15:50 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	init_data(t_data *data)
{
	data->client_pid = 0;
	data->message_length = 0;
	// data->message_buffer = {0};
	// data->received_message = {0};
}

void sigusr1_handler(int signo) 
{
	(void)signo;
    ft_printf("Message reçu par le serveur.\n");
    exit(0);
}

int main(int ac, char **av) 
{
	t_data		data;
	pid_t		server_pid = ft_atoi(av[1]);
    char		*message = av[2];
    int			i = 0;
    if (ac != 3) 
	{
        ft_printf("Tuto: %s <PID du serveur> <message>\n", av[0]);
        return (1);
    }
	init_data(&data);
    // Enregistrez le gestionnaire de signal SIGUSR1
    signal(SIGUSR1, sigusr1_handler);
    // Envoyer la longueur du message au serveur en utilisant SIGUSR1
    kill(server_pid, SIGUSR1);
    while (message[i] != '\0') 
	{
		data.message_buffer[i] = message[i];
        data.message_length++;
        int j = 0;
        while (j < 8) 
		{
            if (message[i] & (1 << j))
                kill(server_pid, SIGUSR2);
            else
                kill(server_pid, SIGUSR1);
            usleep(100);
            j++;
        }
        i++;
    }
    kill(server_pid, SIGUSR1);
    return (0);
}
