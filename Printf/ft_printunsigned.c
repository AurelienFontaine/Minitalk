/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:08:38 by afontain          #+#    #+#             */
/*   Updated: 2022/11/24 16:01:10 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_num_len(unsigned int nbr)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

static char	*ft_uns_itoa(unsigned int n)
{
	char	*nbr;
	int		i;

	i = ft_num_len(n);
	nbr = (char *)malloc(sizeof(char) * (i + 1));
	if (!nbr)
		return (0);
	nbr[i] = '\0';
	while (n != 0)
	{
		nbr[i - 1] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	return (nbr);
}

int	ft_printunsigned(unsigned int n)
{
	int		i;
	char	*nbr;

	i = 0;
	if (n == 0)
		i += write(1, "0", 1);
	else
	{
		nbr = ft_uns_itoa(n);
		i += ft_printstr(nbr);
		free(nbr);
	}
	return (i);
}
