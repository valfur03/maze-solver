/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:46:53 by vfurmane          #+#    #+#             */
/*   Updated: 2020/11/12 10:38:39 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAZE_H
# define MAZE_H

# include <stdlib.h>
# include <time.h>
# include "coord.h"

typedef struct	s_maze
{
	int		width;
	int		height;
	t_coord start;
	t_coord end;
}				t_maze;

int				**ft_init_maze(int width, int height);
t_coord			ft_break_wall(int **maze, t_maze config,
					t_coord cursor, int adj_path);
int				ft_is_blocked(int **maze, t_coord cursor, t_maze config);
int				**ft_break_rand_walls(int **maze, t_maze config);
int				**ft_create_maze(int **maze, t_maze config, t_coord cursor);

#endif
