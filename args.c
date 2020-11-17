/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 09:56:03 by vfurmane          #+#    #+#             */
/*   Updated: 2020/11/17 11:55:27 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

int		ft_init(int argc, char **argv, int *filec, char ***filev)
{
	int	i;
	int	file_i;
	int	graphical;

	if (argc >= 2 && argv[1][0] == '-' && argv[1][1] == 'g' &&
			argv[1][2] == '\0')
	{
		i = 2;
		graphical = 1;
	}
	else
	{
		i = 1;
		graphical = 0;
	}
	*filec = argc - i;
	if (!(*filev = malloc(sizeof(**filev) * *filec)))
		return (-1);
	file_i = 0;
	while (i < argc)
		(*filev)[file_i++] = argv[i++];
	return (graphical);
}
