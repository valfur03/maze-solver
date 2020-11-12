/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:21:25 by vfurmane          #+#    #+#             */
/*   Updated: 2020/11/12 10:39:39 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "coord.h"
#include "maze.h"
#include "str.h"

void	ft_print(int **maze, t_maze config)
{
	int	i;
	int	j;

	i = 0;
	ft_putnbr(config.height);
	ft_putchar('.');
	ft_putchar('*');
	ft_putchar('#');
	ft_putchar('\n');
	while (i < config.height)
	{
		j = -1;
		while (++j < config.width)
		{
			if ((i == 1 && j == 0) ||
					(i == config.height - 2 && j == config.width - 1))
				ft_putchar('*');
			else
				ft_putchar(maze[i][j] == -1 ? '#' : '.');
		}
		ft_putchar('\n');
		i++;
	}
}

void	ft_free_all(int **maze, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(maze[i++]);
	free(maze);
}

int		main(int argc, char **argv)
{
	int		**maze;
	t_maze	config;
	t_coord	cursor;

	if (argc != 3)
	{
		ft_putstr("usage: magen columns rows\n\
				\tcolumns	: number of columns (not like width)\n\
				\trows	: number of rows (not like height)\n");
		return (0);
	}
	config.width = ft_atoi(argv[1]) * 2 + 1;
	config.height = ft_atoi(argv[2]) * 2 + 1;
	cursor.x = 1;
	cursor.y = 1;
	srandom(time(NULL));
	maze = ft_init_maze(config.width, config.height);
	maze = ft_create_maze(maze, config, cursor);
	maze = ft_break_rand_walls(maze, config);
	ft_print(maze, config);
	ft_free_all(maze, config.height);
	return (0);
}
