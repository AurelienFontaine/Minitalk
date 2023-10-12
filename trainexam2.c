/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trainexam2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:01:55 by afontain          #+#    #+#             */
/*   Updated: 2023/10/12 11:55:50 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

// void print_bits(unsigned char octet)
// {
// 	int i = 8;
// 	unsigned char bit;
// 	while (i--)
// 	{
// 		bit = (octet >> 1 & i) + '0'
// 		write(1, &bit, 1);
// 	}
// }

// unsigned char	reverse_bits(unsigned char octet)
// {
// 	int i = 8;
// 	unsigned char rev;

// 	while (i > 0)
// 	{
// 		res = res * 2 + (octet % 2);
// 		octet /= 2;
// 		i--;
// 	}
// }

// unsigned char swap_bits(unsigned char octet)
// {
// 	return ((octet >> 4) | (octet << 4));
// }

int	main(int argc, char *argv[])
{
	int	i;
	int	number;

	if (argc == 2)
	{
		i = 1;
		number = atoi(argv[1]);
		if (number == 1)
			printf("1");
		while (number >= ++i)
		{
			if (number % i == 0)
			{
				printf("%d", i);
				if (number == i)
					break ;
				printf("*");
				number /= i;
				i = 1;
			}
		}
	}
	printf("\n");
	return (0);
}