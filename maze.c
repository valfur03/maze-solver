/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:35:50 by vfurmane          #+#    #+#             */
/*   Updated: 2020/11/11 15:02:43 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maze.h"

int	**ft_get_maze(char *file, t_maze *config)
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
