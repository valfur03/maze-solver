/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:00:48 by vfurmane          #+#    #+#             */
/*   Updated: 2020/11/11 15:00:29 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coord.h"
#include "solver.h"
#include "put.h"
#include "maze.h"

void	ft_prepare_solve(t_coord cursor, t_maze config, int **maze)
{
	cursor.x = config.end.x;
	cursor.y = config.end.y;
	ft_solve(maze, 1, config, cursor);
	ft_print_maze(maze, config);
}

void	ft_free_maze(int **maze, t_maze config)
{
	int	i;

	if (maze)
	{
		i = 0;
		while (i < config.height)
			free(maze[i++]);
		free(maze);
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		**maze;
	int		continue_solve;
	t_maze	config;
	t_coord	cursor;

	i = 1;
	continue_solve = 1;
	while (continue_solve)
	{
		maze = ft_get_maze(argc >= 2 ? argv[i] : NULL, &config);
		if (maze)
		{
			ft_prepare_solve(cursor, config, maze);
		}
		else
			ft_putstr("Error\n");
		i++;
		if (argc == 1)
			continue_solve = 0;
		else
			continue_solve = i < argc - 1;
	}
	ft_free_maze(maze, config);
	return (0);
}
