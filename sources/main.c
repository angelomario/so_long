/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:14:53 by aquissan          #+#    #+#             */
/*   Updated: 2024/07/23 09:22:46 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_matriz(char **map, char *vars)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'E')
				ft_printf("\033[32m%c\033[0m", vars[3]);
			else if (map[y][x] == '1')
				ft_printf("\033[31m%c\033[0m", vars[0]);
			else if (map[y][x] == '0')
				ft_printf("\033[32m%c\033[0m", vars[1]);
			else if (map[y][x] == 'C')
				ft_printf("\033[35m%c\033[0m", vars[2]);
			else if (map[y][x] == 'P')
				ft_printf("\033[32m%c\033[0m", vars[4]);
			else
				ft_printf("\033[0m%c\033[0m", map[y][x]);
		}
		ft_printf("\n");
	}
}

void	showmap(char **map, t_vars vars)
{
	int		x;
	int		y;
	t_point	pos;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			pos.x = x;
			pos.y = y;
			showimage(map[y][x], vars, pos, vars.pictures);
			x++;
		}
		y++;
	}
}

int	main(int ac, char **av)
{
	char	**map;

	if ((ac != 2) || is_valid_file(av[1], ".ber") == 0)
		ft_quit_default(0);
	map = get_mat(av);
	check_map(map);
	map = get_mat(av);
	show_matriz(map, "10CEP");
	ft_game(map);
	free_matriz(map);
	return (0);
}
