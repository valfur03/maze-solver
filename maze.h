/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:46:53 by vfurmane          #+#    #+#             */
/*   Updated: 2020/11/11 14:51:31 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAZE_H
# define MAZE_H

# include <unistd.h>
# include "coord.h"
# include "read.h"
# include "str.h"
# include "parse.h"

typedef struct	s_chrs
{
	char	empty;
	char	filled;
	char	flag;
}				t_chrs;

typedef struct	s_maze
{
	int		width;
	int		height;
	t_chrs	chrs;
	t_coord start;
	t_coord end;
}				t_maze;

int				**ft_get_maze(char *file, t_maze *config);

#endif
