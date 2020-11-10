/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:16:01 by vfurmane          #+#    #+#             */
/*   Updated: 2020/11/10 19:54:34 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include "coord.h"

typedef struct	s_maze
{
	int		width;
	int		height;
	t_coord start;
	t_coord end;
} t_maze;

int	ft_solve(int maze[5][5], int path_index, t_maze config, t_coord cursor);

#endif
