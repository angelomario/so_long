/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:11:28 by aquissan          #+#    #+#             */
/*   Updated: 2024/07/24 10:11:31 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	have_valid_wall(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[x] != NULL)
	{
		if ((map[x][0] != '1') || (map[x][ft_countstr(map[0]) - 1] != '1'))
			return (0);
		x++;
	}
	while (map[0][y] && map[ft_countline(map) - 1][y])
	{
		if (map[0][y] != '1' || map[ft_countline(map) - 1][y] != '1')
			return (0);
		y++;
	}
	return (1);
}

void	fill(char **map, t_point size, t_point cur, char *to_fill)
{
	int	i;

	i = 0;
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
		return ;
	while (to_fill[i])
	{
		if (to_fill[i] == (char)map[cur.y][cur.x])
		{
			map[cur.y][cur.x] = 'F';
			fill(map, size, (t_point){cur.x - 1, cur.y}, to_fill);
			fill(map, size, (t_point){cur.x, cur.y + 1}, to_fill);
			fill(map, size, (t_point){cur.x + 1, cur.y}, to_fill);
			fill(map, size, (t_point){cur.x, cur.y - 1}, to_fill);
		}
		i++;
	}
}

int	ft_ch_in_str(char ch, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

void	fill_exit(char **map, t_point size, t_point cur, char to_fill)
{
	if (to_fill != map[cur.y][cur.x])
	{
		map[cur.y][cur.x] = '0';
		return ;
	}
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
		return ;
	map[cur.y][cur.x] = '0';
	fill_exit(map, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill_exit(map, size, (t_point){cur.x, cur.y + 1}, to_fill);
	fill_exit(map, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill_exit(map, size, (t_point){cur.x, cur.y - 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, "P0C");
	fill_exit(tab, size, begin, 'F');
}
