/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:59:33 by vfurmane          #+#    #+#             */
/*   Updated: 2020/11/11 13:55:05 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strdupcat(char *dest, char *src)
{
	char			*res;
	unsigned long	i;
	unsigned long	dest_start;
	unsigned long	src_size;

	i = 0;
	dest_start = 0;
	while (dest[i++])
		dest_start++;
	i = 0;
	src_size = 0;
	while (src[i++])
		src_size++;
	i = -1;
	if (!(res = malloc(sizeof(*res) * (dest_start + src_size + 1))))
		exit(0);
	while (dest[++i])
		res[i] = dest[i];
	i = -1;
	while (src[++i])
		res[dest_start + i] = src[i];
	free(dest);
	res[dest_start + i] = '\0';
	return (res);
}

int		ft_atoi(const char *str)
{
	int	i;
	int	nbr;

	nbr = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + str[i++] - '0';
	return (nbr);
}
