/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:00:48 by vfurmane          #+#    #+#             */
/*   Updated: 2020/11/11 16:03:00 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coord.h"
#include "solver.h"
#include "put.h"
#include "maze.h"

void	ft_print_title(char *title, int i)
{
	if (i > 1)
		ft_putstr("\n");
	ft_putstr("===== ");
	ft_putstr(title);
	ft_putstr(" =====");
	ft_putstr("\n\n");
}

void	ft_prepare_solve(t_coord cursor, t_maze config, int **maze)
{
	if (maze)
	{
		cursor.x = config.end.x;
		cursor.y = config.end.y;
		ft_solve(maze, 1, config, cursor);
		ft_print_maze(maze, config);
	}
	else
		ft_putstr("Error\n");
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
		if (argc >= 2)
			ft_print_title(argv[i], i);
		maze = ft_get_maze(argc >= 2 ? argv[i] : NULL, &config);
		ft_prepare_solve(cursor, config, maze);
		i++;
		if (argc == 1)
			continue_solve = 0;
		else
			continue_solve = i < argc;
	}
	ft_free_maze(maze, config);
	return (0);
}
