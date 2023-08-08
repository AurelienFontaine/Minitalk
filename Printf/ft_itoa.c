/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:35:16 by afontain          #+#    #+#             */
/*   Updated: 2022/11/24 13:00:22 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_digit(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

char	*ft_itoa(int c)
{
	char		*str_num;
	size_t		i;
	size_t		count;
	long int	x;

	i = 0;
	x = (long int)c;
	count = ft_get_digit(x);
	str_num = (char *)malloc((count + 1) * sizeof(char));
	if (!str_num)
		return (NULL);
	if (x < 0)
	{
		str_num[0] = '-';
		x *= -1;
		i++;
	}
	str_num[count] = '\0';
	while (count-- > i)
	{
		str_num[count] = (x % 10) + '0';
		x /= 10;
	}
	return (str_num);
}
