/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printHexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:00:03 by afontain          #+#    #+#             */
/*   Updated: 2022/11/24 16:01:18 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexa_len(unsigned int nbr)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		i++;
		nbr = nbr / 16;
	}
	return (i);
}

static void	ft_hexa(unsigned int nbr, const char base)
{
	if (nbr >= 16)
	{
		ft_hexa(nbr / 16, base);
		ft_hexa(nbr % 16, base);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar(nbr + '0');
		else
		{
			if (base == 'x')
				ft_putchar(nbr - 10 + 'a');
			if (base == 'X')
				ft_putchar(nbr - 10 + 'A');
		}
	}
}

int	ft_printhexa(unsigned int nbr, const char base)
{
	if (nbr == 0)
		return (write(1, "0", 1));
	else
		ft_hexa(nbr, base);
	return (ft_hexa_len(nbr));
}
