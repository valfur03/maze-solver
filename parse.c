/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:36:16 by vfurmane          #+#    #+#             */
/*   Updated: 2020/11/11 14:46:28 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_maze	ft_config_maze(char *str, t_maze *config)
{
	int	i;
	int	len;

	config->height = ft_atoi(str);
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	config->chrs.empty = str[i++];
	config->chrs.flag = str[i++];
	config->chrs.filled = str[i++];
	len = 0;
	while (str[i] != '\n')
		i++;
	i++;
	while (str[i++] != '\n')
		len++;
	config->width = len;
	config->start.x = -1;
	return (*config);
}

void	ft_add_flag(t_maze *config, int y, int x)
{
	if (config->start.x == -1)
	{
		config->start.x = x;
		config->start.y = y;
	}
	else
	{
		config->end.x = x;
		config->end.y = y;
	}
}

int		ft_fill_maze(char *buffer, int **maze, t_maze *config, int y)
{
	int	x;

	x = 0;
	while (buffer[x] && x < config->width)
	{
		if (x >= config->width)
			return (0);
		if (buffer[x] == config->chrs.filled)
			maze[y][x] = -1;
		else if (buffer[x] == config->chrs.empty ||
				buffer[x] == config->chrs.flag)
			maze[y][x] = 0;
		else
			return (0);
		if (buffer[x] == config->chrs.flag)
			ft_add_flag(config, y, x);
		x++;
	}
	return (x);
}

int		**ft_parse_map(char *buffer, int **maze, t_maze *config)
{
	int	i;
	int	ret;
	int	buffer_i;

	i = 0;
	buffer_i = 0;
	while (i < config->height)
	{
		if (!(maze[i] = malloc(sizeof(**maze) * config->width)))
			return (NULL);
		if (!(ret = ft_fill_maze(&buffer[buffer_i], maze, config, i)))
			return (NULL);
		if (buffer[buffer_i + ret] != '\n')
			return (NULL);
		buffer_i += ret + 1;
		i++;
	}
	return (maze);
}

int		**ft_parse_maze(char *buffer, t_maze *config)
{
	int	i;
	int	**maze;

	ft_config_maze(buffer, config);
	i = 0;
	while (buffer[i] && buffer[i] >= '0' && buffer[i] <= '9')
		i++;
	buffer = &buffer[i] + 4 * sizeof(*buffer);
	if (!(maze = malloc(sizeof(*maze) * config->height)))
		return (NULL);
	if (!ft_parse_map(buffer, maze, config))
		return (NULL);
	return (maze);
}
