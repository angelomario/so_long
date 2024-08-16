/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:04:27 by aquissan          #+#    #+#             */
/*   Updated: 2024/07/30 09:04:44 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_countline(char **map)
{
	int	i;

	i = 0;
	if (map == NULL || *map == NULL)
		return (0);
	while (map[i] != NULL)
		i++;
	return (i);
}

int	ft_countstr(char *str)
{
	int	i;
	int	length;

	i = 0;
	while (ft_ch_in_str(str[i], "10CEP"))
		i++;
	length = i;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '\0')
		i = 0;
	return (length + i);
}

int	is_valid_map(char **map)
{
	int	i;
	int	tam;

	if (map == NULL || *map == NULL)
		return (0);
	i = 0;
	tam = ft_countstr(map[i++]);
	while (map[i] && (ft_countstr(map[i]) == tam))
		i++;
	return (map[i] == NULL);
}

t_point	get_start_var(char **map, char var)
{
	int		x;
	int		y;
	t_point	start;

	x = 0;
	y = 0;
	start.x = 0;
	start.y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x])
		{
			if ((char)map[y][x] == var)
			{
				start.x = x;
				start.y = y;
				break ;
			}
			x++;
		}
		y++;
	}
	return (start);
}

void	check_map(char **map)
{
	int		i;

	i = -1;
	if (!is_valid_map(map))
		i = 1;
	else if ((ft_count_var_game(map, 'E') != 1)
		|| (ft_count_var_game(map, 'C') < 1)
		|| (ft_count_var_game(map, 'P') != 1))
		i = 3;
	else if (!have_valid_wall(map))
		i = 1;
	else if (ft_countline(map) == ft_countstr(map[0]))
		i = 1;
	else if ((ft_countstr(map[0]) > 48) || ft_countline(map) > 27)
		i = 5;
	flood_fill(map, (t_point){ft_countstr(map[0]), ft_countline(map)},
		get_start_var(map, 'P'));
	if ((ft_count_var_game(map, 'E') >= 1)
		|| (ft_count_var_game(map, 'C') >= 1)
		|| (ft_count_var_game(map, 'P') >= 1))
		i = 4;
	free_matriz(map);
	ft_quit_default(i);
}
