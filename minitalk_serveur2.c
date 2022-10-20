/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_serveur.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:07:27 by whamoumi          #+#    #+#             */
/*   Updated: 2021/06/11 14:32:30 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	ft_putnbr(int nb)
{
	long	nbr;

	nbr = nb;
	if (nbr == 2147483648)
	{
		ft_putchar('-');
		write(1, "2147483648", 10);
	}
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
	}
	if (nbr >= 0 && nbr <= 9)
	{
		ft_putchar(nbr + '0');
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putchar((nbr % 10) + '0');
	}
}

char	*ft_strjoin(char *s1, char s2)
{
	char	*res;
	int		i;
	int		y;

	res = malloc(sizeof(char) * (ft_strlen(s1) + 2));
	i = -1;
	y = 0;
	if (!res)
		return (NULL);
	while (s1[++i])
		res[y++] = s1[i];
	res[y] = s2;
	y++;
	res[y] = '\0';
	return (res);
}
