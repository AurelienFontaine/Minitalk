/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:20:17 by afontain          #+#    #+#             */
/*   Updated: 2023/10/16 13:20:32 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../printf/ft_printf.h"
# include <signal.h>
# include <sys/types.h>

void	init_sig(int sig, void (*handler)(int, siginfo_t *, void *));
int		ft_strlen(char *str);
int		ft_atoi(char *str);

#endif