/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:52:38 by vfurmane          #+#    #+#             */
/*   Updated: 2020/11/12 10:27:21 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

void	ft_putnbr(int nbr)
{
	unsigned int	nb;

	nb = (nbr < 0) ? -nbr : nbr;
	if (nbr < 0)
		ft_putchar('-');
	if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}

int		ft_atoi(const char *str)
{
	int	i;
	int	nbr;

	nbr = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + str[i++] - '0';
	return (nbr);
}
