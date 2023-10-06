/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:41:29 by afontain          #+#    #+#             */
/*   Updated: 2023/10/05 12:29:20 by afontain         ###   ########.fr       */
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
