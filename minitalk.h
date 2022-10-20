/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:00:08 by whamoumi          #+#    #+#             */
/*   Updated: 2021/06/11 14:34:30 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include <stdlib.h>

int		ft_strlen(char *str);
int		*give_binary(char c);
int		ft_iterative_power(int nb, int power);
int		ft_atoi(const char *str);
int		bit_to_char(char *str);
int		ft_strlen(char *str);
void	ft_rev_int_tab(int *tab, int size);
void	handle(int sig);
void	bits_to_char(int d);
char	*ft_strjoin(char *s1, char s2);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
void	ft_putchar(char c);
char	*ft_strcpy(char *dest, char *src);
#endif
