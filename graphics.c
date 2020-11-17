/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:14:34 by vfurmane          #+#    #+#             */
/*   Updated: 2020/11/17 11:11:42 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

SDL_Window		*ft_create_window(char *name, t_maze config)
{
	SDL_Window	*win;

	win = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, config.width * 20, config.height * 20,
			SDL_WINDOW_SHOWN);
	return (win);
}

SDL_Renderer	*ft_create_renderer(SDL_Window *win)
{
	SDL_Renderer	*renderer;

	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	return (renderer);
}

void			ft_print_maze_win(SDL_Renderer *renderer, int **maze, t_maze config)
{
	int			x;
	int			y;
	SDL_Rect	rectangle;

	rectangle.w = 20;
	rectangle.h = 20;
	y = 0;
	while (y < config.height)
	{
		x = 0;
		while (x < config.width)
		{
			rectangle.x = x * 20;
			rectangle.y = y * 20;
			if (maze[y][x] >= 0)
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			else if (maze[y][x] == -1)
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			else if (maze[y][x] == -2)
				SDL_SetRenderDrawColor(renderer, 255, 127, 40, 255);
			x++;
			SDL_RenderFillRect(renderer, &rectangle);
		}
		y++;
	}
	SDL_RenderPresent(renderer);
}

void		ft_win_maze(char *name, t_maze config, int **maze)
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_bool		quit;
	SDL_Event		event;

	if ((win = ft_create_window(name, config)) == NULL)
		return ;
	if ((renderer = ft_create_renderer(win)) == NULL)
		return ;
	ft_print_maze_win(renderer, maze, config);
	quit = SDL_FALSE;
	while (!quit)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
			quit = SDL_TRUE;
	}
	SDL_DestroyWindow(win);
}
