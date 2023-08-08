/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:37:56 by afontain          #+#    #+#             */
/*   Updated: 2023/08/08 15:22:19 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_printstr(char *str);
int		ft_printnbr(int n);
int		ft_printhexa(unsigned int nbr, const char base);
int		ft_printptr(unsigned long long ptr);
char	*ft_itoa(int c);
int		ft_printunsigned(unsigned int n);

#endif
