/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:20:17 by afontain          #+#    #+#             */
/*   Updated: 2023/10/06 13:00:59 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../printf/ft_printf.h"
# include <signal.h>
# include <sys/types.h>
# include <wchar.h>

// Structure pour stocker les données du serveur
typedef struct	s_data
{
    pid_t	client_pid;
    char	received_message[256];
	char	message_buffer[256];
    int		message_length;
}				t_data;

//Client

//Server
// void	init_server(t_data *data);
void	init_data(t_data *data);

//Utils
int		ft_strlen(char *str);
int		ft_atoi(char *str);
// void	ft_putstr(char *str);
// void	ft_putnbr(int n);
void	*ft_memset(void *str, int c, size_t n);

#endif