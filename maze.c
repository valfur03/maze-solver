/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:35:50 by vfurmane          #+#    #+#             */
/*   Updated: 2020/11/17 12:07:01 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maze.h"

int		**ft_get_maze(char *file, t_maze *config)
{
	int		**maze;
	char	*buffer;

	if (!(buffer = ft_read_file(file)))
		return (NULL);
	if (!(maze = ft_parse_maze(buffer, config)))
		return (NULL);
	free(buffer);
	return (maze);
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
