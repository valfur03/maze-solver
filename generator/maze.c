/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 10:21:50 by vfurmane          #+#    #+#             */
/*   Updated: 2020/11/12 10:38:00 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maze.h"

int		**ft_init_maze(int width, int height)
{
	int	i;
	int	j;
	int	**maze;

	if (!(maze = malloc(sizeof(*maze) * height)))
		return (NULL);
	i = 0;
	while (i < height)
	{
		if (!(maze[i] = malloc(sizeof(**maze) * width)))
			return (NULL);
		j = 0;
		while (j < width)
		{
			if (i % 2 == 0)
				maze[i][j] = -1;
			else
				maze[i][j] = j % 2 == 0 ? -1 : 0;
			j++;
		}
		i++;
	}
	return (maze);
}

t_coord	ft_break_wall(int **maze, t_maze config, t_coord cursor, int adj_path)
{
	if (adj_path == 0 && cursor.y > 1)
	{
		maze[cursor.y - 1][cursor.x] = 1;
		maze[cursor.y - 2][cursor.x] = 1;
		cursor.y -= 2;
	}
	else if (adj_path == 1 && cursor.x < config.width - 2)
	{
		maze[cursor.y][cursor.x + 1] = 1;
		maze[cursor.y][cursor.x + 2] = 1;
		cursor.x += 2;
	}
	else if (adj_path == 2 && cursor.y < config.height - 2)
	{
		maze[cursor.y + 1][cursor.x] = 1;
		maze[cursor.y + 2][cursor.x] = 1;
		cursor.y += 2;
	}
	else if (adj_path == 3 && cursor.x > 1)
	{
		maze[cursor.y][cursor.x - 1] = 1;
		maze[cursor.y][cursor.x - 2] = 1;
		cursor.x -= 2;
	}
	return (cursor);
}

int		ft_is_blocked(int **maze, t_coord cursor, t_maze config)
{
	int w;
	int	h;

	w = config.width;
	h = config.height;
	return ((maze[cursor.y > 1 ? cursor.y - 2 : 1][cursor.x] == 1) &&
			(maze[cursor.y][cursor.x < w - 2 ? cursor.x + 2 : w - 2] == 1) &&
			(maze[cursor.y < h - 2 ? cursor.y + 2 : h - 2][cursor.x] == 1) &&
			(maze[cursor.y][cursor.x > 1 ? cursor.x - 2 : 1] == 1));
}

int		**ft_break_rand_walls(int **maze, t_maze config)
{
	int	i;
	int	x;
	int	y;
	int	maze_size;

	i = 0;
	maze_size = ((config.width + config.height) / 2 - 1) / 2;
	while (i < maze_size)
	{
		x = random() % (config.width - 2) + 1;
		if (x % 2 == 0)
			y = (random() % ((config.height - 1) / 2)) * 2 + 1;
		else
			y = (random() % ((config.height - 2) / 2)) * 2 + 2;
		maze[y][x] = 1;
		i++;
	}
	return (maze);
}

int		**ft_create_maze(int **maze, t_maze config, t_coord cursor)
{
	int		adj_path_index;
	t_coord new_cursor;

	adj_path_index = 0;
	maze[cursor.y][cursor.x] = 1;
	while (!ft_is_blocked(maze, cursor, config))
	{
		adj_path_index = random() % 4;
		new_cursor = ft_break_wall(maze, config, cursor, adj_path_index);
		if (new_cursor.x != cursor.x || new_cursor.y != cursor.y)
			ft_create_maze(maze, config, new_cursor);
	}
	return (maze);
}
