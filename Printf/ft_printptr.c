/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:09:05 by afontain          #+#    #+#             */
/*   Updated: 2022/11/24 15:54:26 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// printf("prtlen : %d\n", i);
static int	ft_ptrlen(uintptr_t n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static void	ft_putptr(uintptr_t n)
{
	if (n >= 16)
	{
		ft_putptr(n / 16);
		ft_putptr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'a');
	}
}

int	ft_printptr(unsigned long long ptr)
{
	int	i;

	i = 0;
	if (ptr == 0)
	{
		i += write(1, "(nil)", 5);
		return (i);
	}
	i += write(1, "0x", 2);
	ft_putptr(ptr);
	i += ft_ptrlen(ptr);
	return (i);
}
