/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:25:22 by aquissan          #+#    #+#             */
/*   Updated: 2024/08/02 15:27:27 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_right(t_map *map, t_point position, t_activity activity,
		t_pitures pictures)
{
	if (map->map[position.y][position.x + 1] == 'E' && activity.colate == 0)
		end_game(map, position);
	if (map->map[position.y][position.x + 1] == '0'
			|| map->map[position.y][position.x + 1] == 'C')
	{
		map->map[position.y][position.x + 1] = 'P';
		map->map[position.y][position.x] = '0';
		showimage ('0', map->vars, position, pictures);
		position.x++;
		showimage ('r', map->vars, position, pictures);
		return (1);
	}
	return (0);
}

int	move_left(t_map *map, t_point position, t_activity activity,
		t_pitures pictures)
{
	if (map->map[position.y][position.x - 1] == 'E' && activity.colate == 0)
		end_game(map, position);
	if (map->map[position.y][position.x - 1] == '0'
			|| map->map[position.y][position.x - 1] == 'C')
	{
		map->map[position.y][position.x - 1] = 'P';
		map->map[position.y][position.x] = '0';
		showimage('0', map->vars, position, pictures);
		position.x--;
		showimage('l', map->vars, position, pictures);
		return (1);
	}
	return (0);
}

int	move_up(t_map *map, t_point position, t_activity activity,
		t_pitures pictures)
{
	if (map->map[position.y - 1][position.x] == 'E' && activity.colate == 0)
		end_game(map, position);
	if (map->map[position.y - 1][position.x] == '0'
			|| map->map[position.y - 1][position.x] == 'C')
	{
		map->map[position.y - 1][position.x] = 'P';
		map->map[position.y][position.x] = '0';
		showimage('0', map->vars, position, pictures);
		position.y--;
		showimage('r', map->vars, position, pictures);
		return (1);
	}
	return (0);
}

int	move_down(t_map *map, t_point position, t_activity activity,
		t_pitures pictures)
{
	if (map->map[position.y + 1][position.x] == 'E'
			&& activity.colate == 0)
		end_game(map, position);
	if ((map->map[position.y + 1][position.x] == '0')
			|| map->map[position.y + 1][position.x] == 'C')
	{
		map->map[position.y + 1][position.x] = 'P';
		map->map[position.y][position.x] = '0';
		showimage('0', map->vars, position, pictures);
		position.y++;
		showimage('l', map->vars, position, pictures);
		return (1);
	}
	return (0);
}

int	move(int key_code, t_map *map)
{
	static t_activity	activity;

	activity.colate = count_var(map->map, 'C');
	if (activity.colate == 0)
		showimage('e', map->vars, get_start_var(map->map, 'E'),
			map->vars.pictures);
	if (key_code == 65307)
		end_game(map, get_start_var(map->map, 'P'));
	if ((char)key_code == 'S')
		activity.moves += move_right(map, get_start_var(map->map, 'P'),
				activity, map->vars.pictures);
	if ((char)key_code == 'T')
		activity.moves += move_down(map, get_start_var(map->map, 'P'),
				activity, map->vars.pictures);
	if ((char)key_code == 'Q')
		activity.moves += move_left(map, get_start_var(map->map, 'P'),
				activity, map->vars.pictures);
	if ((char)key_code == 'R')
		activity.moves += move_up(map, get_start_var(map->map, 'P'),
				activity, map->vars.pictures);
	show_matriz(map->map, "#.CEP");
	ft_printf("Moves: \033[32m%d\033[0m\n", activity.moves);
	ft_printf("Colate: \033[32m%d\033[0m\n", activity.colate);
	return (1);
}
