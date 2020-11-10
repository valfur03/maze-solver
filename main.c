/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:00:48 by vfurmane          #+#    #+#             */
/*   Updated: 2020/11/10 21:27:32 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "coord.h"
#include "solver.h"
#include "put.h"

int	main()
{
	int				maze[5][5] = {
								{-1, -1, -1, -1, -1}, 
								{0, 0, 0, 0, -1}, 
								{-1, 0, -1, -1, -1}, 
								{-1, 0, 0, 0, 0}, 
								{-1, -1, -1, -1, -1}};
	t_maze	config;
	config.width = 5;
	config.height = 5;
	config.start.x = 0;
	config.start.y = 1;
	config.end.x = 4;
	config.end.y = 3;
	t_coord	cursor;
	cursor.x = config.end.x;
	cursor.y = config.end.y;
	ft_solve(maze, 1, config, cursor);
	ft_print_maze(maze, config);
	return (0);
}
