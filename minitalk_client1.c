/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:01:15 by whamoumi          #+#    #+#             */
/*   Updated: 2021/06/11 14:31:22 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	signe;
	int	res;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	signe = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return ((res * signe));
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = size - 1;
	while (i < (size / 2))
	{
		tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
		i++;
		j--;
	}
}

int	*give_binary(char c)
{
	int	i;
	int	*tab;

	tab = malloc(sizeof(int) * 8);
	i = 0;
	if (!tab)
		return (0);
	while (i < 8)
	{
		tab[i] = c % 2;
		i++;
		c /= 2;
	}
	ft_rev_int_tab(tab, 8);
	return (tab);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int	*tab;
	int	i;
	int	j;
	int	pid;

	(void)argc;
	pid = ft_atoi(argv[1]);
	j = -1;
	while (++j < ft_strlen(argv[2]) + 1)
	{
		i = -1;
		tab = give_binary(argv[2][j]);
		while (++i < 8)
		{
			if (tab[i] == 1)
				kill(pid, SIGUSR1);
			else if (tab[i] == 0)
				kill(pid, SIGUSR2);
			usleep(235);
		}
		free(tab);
	}
	return (0);
}
