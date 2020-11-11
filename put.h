/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:32:19 by vfurmane          #+#    #+#             */
/*   Updated: 2020/11/11 12:29:25 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_H
# define PUT_H

# include <unistd.h>
# include "solver.h"

void	ft_putstr(char *str);
void	ft_print_maze(int **maze, t_maze config);

#endif
