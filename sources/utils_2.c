/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:49:27 by aquissan          #+#    #+#             */
/*   Updated: 2024/08/14 12:50:51 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_var(char **map, char var)
{
	int	x;
	int	y;
	int	qtd_var;

	qtd_var = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == var)
				qtd_var++;
			x++;
		}
		y++;
	}
	return (qtd_var);
}

int	ft_count_var_game(char **map, char var)
{
	int	i;
	int	j;
	int	qtd;

	j = 0;
	qtd = 0;
	if (map == NULL || map[0] == NULL)
		return (0);
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			if (map[j][i] == var)
				qtd++;
			i++;
		}
		j++;
	}
	return (qtd);
}

char	**get_mat(char **av)
{
	int		fd;
	int		i;
	char	buf[2];
	char	str[10000];
	char	**mat;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_quit_default(2);
	while (read(fd, &(*buf), 1))
		str[i++] = buf[0];
	str[i] = '\0';
	close(fd);
	mat = ft_split(str);
	return (mat);
}
