/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:33:24 by afontain          #+#    #+#             */
/*   Updated: 2023/10/06 14:49:10 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

t_data *data;

// Gestionnaire pour le signal SIGUSR1 (réception de la longueur du message)
void sigusr1_handler(int signo)
{
	(void)signo;
	data->client_pid = getpid(); // Enregistre le PID du client
	printf("%i", data->client_pid);
    data->message_length = 0;     // Réinitialise la longueur du message
}

// Gestionnaire pour le signal SIGUSR2 (réception du caractère)
void sigusr2_handler(int signo) 
{
	(void)signo;
    // Vérifiez que le client_pid est différent de zéro
    if (data->client_pid != 0) 
	{
		printf("%i\n", data->message_length);
		printf("%i\n", ft_strlen(data->received_message));
        if (data->message_length < ft_strlen(data->received_message) / ft_strlen(data->received_message[0]))
            data->received_message[data->message_length++] = (char)signo;
        // Vérifiez si le message est complet
    if (data->received_message[data->message_length] == '\0') 
	{
    	ft_printf("Message reçu du client %d : %s\n", data->client_pid, data->received_message);
        //  Envoyer une confirmation au client en utilisant SIGUSR1
		kill(data->client_pid, SIGUSR1);
        //    Réinitialiser les variables
        data->client_pid = 0;
        data->message_length = 0;
        ft_memset(data->received_message, 0, sizeof(data->received_message));
    }
	else
        ft_printf("Erreur : Aucun client en attente.\n");
}

// void sigusr2_handler(int signo) 
// {
//     if (data->client_pid == 0) 
// 	{
//         ft_printf("Erreur : Aucun client en attente.\n");
//         return ;
//     }
//     // Vérifiez la longueur du message
//     if (data->message_length < sizeof(data->received_message) / sizeof(data->received_message[0]))
//         data->received_message[data->message_length++] = (char)signo;
//     // Vérifiez si le message est complet
//     if (data->received_message[data->message_length - 1] == '\0') 
// 	{
//         ft_printf("Message reçu du client %d : %ls\n", data->client_pid, data->received_message);
//         // Envoyer une confirmation au client en utilisant SIGUSR1
//         kill(data->client_pid, SIGUSR1);
//         data->client_pid = 0;
//         data->message_length = 0;
//         ft_memset(data->received_message, 0, sizeof(data->received_message));
//     }
// }

int main(int ac, char **av) 
{
	(void)av;
    pid_t	server_pid;
	server_pid = getpid();
	if (ac != 1)
	{
		ft_printf("Pas besoin de parametres\n");
		return (0);
	}
    ft_printf("Serveur lancé avec PID : %d\n", server_pid);
    signal(SIGUSR1, sigusr1_handler);
    signal(SIGUSR2, sigusr2_handler);
    while (1)
        sleep(-1);
    return (0);
}

