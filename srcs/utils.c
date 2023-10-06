/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:19:10 by afontain          #+#    #+#             */
/*   Updated: 2023/10/06 12:25:27 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)str)[i] = c;
		i++;
	}
	return (str);
}

// void	ft_putstr(char *str)
// {
// 	write(1, str, ft_strlen(str));
// }

// void	ft_putnbr(int n)
// {
// 	if (n < 0)
// 	{
// 		write(1, "-", 1);
// 		n *= -1;
// 	}
// 	if (n < 10)
// 	{
// 		ft_putchar(n + 48);
// 	}
// 	if (n > 9)
// 	{
// 		ft_putnbr(n / 10);
// 		ft_putchar((n % 10) + 48);
// 	}
// }

int ft_atoi(char *str)
{
	int i;
	int nb;
	int signe;
	
	i = 0;
	nb = 0;
	signe = 1;
	if (str == NULL)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' ' && str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb * signe);
}

// Gestionnaire pour le signal SIGUSR2 (réception du caractère)

