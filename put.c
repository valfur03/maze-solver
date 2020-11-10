/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:31:39 by vfurmane          #+#    #+#             */
/*   Updated: 2020/11/10 21:26:34 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_maze(int maze[5][5], t_maze config)
{
	int	x;
	int	y;

	y = 0;
	while (y < config.height)
	{
		x = 0;
		while (x < config.width)
		{
			if (maze[y][x] >= 0)
				ft_putchar(' ');
			else if (maze[y][x] == -1)
				ft_putchar('#');
			else if (maze[y][x] == -2)
				ft_putchar('.');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
