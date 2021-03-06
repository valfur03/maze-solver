/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:17:20 by vfurmane          #+#    #+#             */
/*   Updated: 2020/11/11 16:40:24 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

t_coord	ft_move_cursor(t_coord cursor, int adj_path_index, t_maze config)
{
	if (adj_path_index == 0 && cursor.y > 0)
		cursor.y -= 1;
	else if (adj_path_index == 1 && cursor.x < config.width - 1)
		cursor.x += 1;
	else if (adj_path_index == 2 && cursor.y < config.height - 1)
		cursor.y += 1;
	else if (adj_path_index == 3 && cursor.x > 0)
		cursor.x -= 1;
	return (cursor);
}

void	ft_draw_path(int **maze, t_maze config, t_coord cursor)
{
	int		adj_path_index;
	int		current_path_index;
	t_coord	new_cursor;

	current_path_index = maze[cursor.y][cursor.x];
	maze[cursor.y][cursor.x] = -2;
	adj_path_index = 0;
	while (adj_path_index < 4)
	{
		new_cursor = ft_move_cursor(cursor, adj_path_index++, config);
		if (maze[new_cursor.y][new_cursor.x] < current_path_index
				&& maze[new_cursor.y][new_cursor.x] > 0)
		{
			ft_draw_path(maze, config, new_cursor);
			break ;
		}
	}
}

int		ft_solve(int **maze, int path_index, t_maze config, t_coord cursor)
{
	int		adj_path_index;
	t_coord	new_cursor;

	if (maze[cursor.y][cursor.x] < 0)
		return (0);
	if (maze[cursor.y][cursor.x] > 0 && maze[cursor.y][cursor.x] < path_index)
		return (0);
	maze[cursor.y][cursor.x] = path_index;
	if (cursor.x == config.start.x && cursor.y == config.start.y)
		return (1);
	adj_path_index = 0;
	while (adj_path_index < 4)
	{
		new_cursor = ft_move_cursor(cursor, adj_path_index++, config);
		ft_solve(maze, path_index + 1, config, new_cursor);
	}
	if (path_index == 1)
		ft_draw_path(maze, config, config.start);
	return (1);
}
