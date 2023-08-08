/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:51:33 by afontain          #+#    #+#             */
/*   Updated: 2023/08/08 15:26:27 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

static int	ft_printf1(const char c, va_list ptr)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(ptr, int));
	else if (c == 's')
		count += ft_printstr(va_arg(ptr, char *));
	else if (c == 'p')
		count += ft_printptr(va_arg(ptr, unsigned long));
	else if (c == 'd' || c == 'i')
		count += ft_printnbr(va_arg(ptr, int));
	else if (c == 'u')
		count += ft_printunsigned(va_arg(ptr, unsigned int));
	else if (c == 'x' || c == 'X')
		count += ft_printhexa(va_arg(ptr, unsigned int), c);
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	size_t	i;
	int		count;

	va_start(ptr, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_printf1(str[i + 1], ptr);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ptr);
	return (count);
}

// int main(void)
// {	
// 		char *ptr;
// 		char s[4] = "iso";
// 		ptr = s;
		
		
// 		ft_printf("%p",ptr);
		
		
// 	/*	printf("Vrai Retour : [%d]\n", printf("%p",0));
// 		printf("Mien Retour : [%d]\n", ft_printf("%p",0));
//         return (0);*/
// } 
