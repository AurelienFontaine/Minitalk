/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:41:29 by afontain          #+#    #+#             */
/*   Updated: 2023/10/03 18:16:42 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		ft_printf("Don't need parameters");
		exit(EXIT_FAILURE);	
	}
}
