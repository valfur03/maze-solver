/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:48:26 by vfurmane          #+#    #+#             */
/*   Updated: 2020/11/11 13:54:46 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

char	*ft_read_file(char *file)
{
	int		fd;
	int		ret;
	char	buffer[BUF_SIZE + 1];
	char	*file_content;

	if (file)
	{
		if ((fd = open(file, O_RDWR)) == -1)
			return (NULL);
	}
	else
		fd = 0;
	if (!(file_content = malloc(sizeof(*file_content))))
		return (NULL);
	*file_content = '\0';
	while ((ret = read(fd, buffer, BUF_SIZE)))
	{
		buffer[ret] = '\0';
		file_content = ft_strdupcat(file_content, buffer);
	}
	return (file_content);
}
