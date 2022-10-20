/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 09:44:41 by whamoumi          #+#    #+#             */
/*   Updated: 2021/06/11 14:30:46 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	acc;

	i = 0;
	acc = 1;
	if (power < 0)
		return (0);
	while (++i <= power)
		acc = acc * nb;
	return (acc);
}

int	bit_to_char(char *str)
{
	int	i;
	int	nbr;
	int	puissance;

	nbr = 0;
	puissance = 7;
	i = 0;
	while (i < 8)
	{
		if (str[i] == '1')
			nbr += ft_iterative_power(2, puissance);
		else if (str[i] == '0')
			nbr += 0;
		puissance--;
		i++;
	}
	return (nbr);
}

void	bits_to_char(int d)
{
	static char	*tab = "";
	int			c;
	static char	tab1[8] = "        ";

	tab = ft_strjoin(tab, '0' + d);
	ft_strcpy(tab1, tab);
	free(tab);
	if (ft_strlen(tab1) == 8)
	{
		c = bit_to_char(tab1);
		write(1, &c, 1);
		if (c == 0)
			write(1, "\n", 1);
		tab = "";
	}
}

void	handle(int sig)
{
	if (sig == SIGUSR1)
		bits_to_char(1);
	if (sig == SIGUSR2)
		bits_to_char(0);
}

int	main(void)
{
	ft_putstr("le PID : ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	signal(SIGUSR1, handle);
	signal(SIGUSR2, handle);
	while (1)
		pause();
}
