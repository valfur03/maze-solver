/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:00:48 by vfurmane          #+#    #+#             */
/*   Updated: 2020/11/17 11:55:41 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coord.h"
#include "solver.h"
#include "put.h"
#include "maze.h"
#include "graphics.h"
#include "args.h"

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
	}
	else
		ft_putstr("Error\n");
}

void	ft_loop_solve(int filec, char **filev, int i, int graphical)
{
	int			**maze;
	t_maze		config;
	t_coord		cursor;

	maze = ft_get_maze(filec >= 1 ? filev[i] : NULL, &config);
	ft_prepare_solve(cursor, config, maze);
	if (graphical)
		ft_win_maze(filec >= 1 ? filev[i] : NULL, config, maze);
	else
	{
		if (filec >= 2)
			ft_print_title(filev[i], i);
		ft_print_maze(maze, config);
	}
	ft_free_maze(maze, config);
}

int		main(int argc, char **argv)
{
	int		i;
	int		graphical;
	int		continue_solve;
	int		filec;
	char	**filev;

	SDL_Init(SDL_INIT_VIDEO);
	graphical = ft_init(argc, argv, &filec, &filev);
	i = 1;
	continue_solve = 1;
	while (continue_solve)
	{
		ft_loop_solve(filec, filev, i - 1, graphical);
		if (filec == 0)
			continue_solve = 0;
		else
			continue_solve = i < filec;
		i++;
	}
	SDL_Quit();
	free(filev);
	return (0);
}
