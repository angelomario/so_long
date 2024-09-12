/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_enemies_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:22:36 by aquissan          #+#    #+#             */
/*   Updated: 2024/08/29 14:23:32 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	reset_enemies_directions(t_vars *vars)
{
	int	qtd;

	qtd = ft_count_var_game(vars->map, 'N');
	while (qtd--)
	{
		vars->enemies[qtd].in_move = 1;
		vars->enemies[qtd].direction = rand_direction(1, 4);
		if (vars->enemies[qtd].direction == 'R')
			vars->enemies[qtd].orc_see = 3;
		else if (vars->enemies[qtd].direction == 'E')
			vars->enemies[qtd].orc_see = 2;
	}
	detect_rogue(vars);
}

void	update_position(t_vars *vars, char **map)
{
	int	x;
	int	y;
	int	i;

	i = ft_count_var_game(map, 'N');
	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'N')
			{
				vars->enemies[--i].position = (t_point){x, y};
				vars->enemies[i].index = i;
			}
		}
	}
}

void	initialize_enemies(t_vars *vars, char **map)
{
	int	x;
	int	y;
	int	i;

	i = ft_count_var_game(map, 'N');
	vars->enemies = (t_enemy *)malloc(sizeof(t_enemy) * i);
	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'N')
			{
				vars->enemies[--i] = (t_enemy){(t_point){x, y}, 1, 0, 0, '\0',
					get_direction_p(*vars, 'N', (t_point){x, y}), 0, 2500, i, 0,
					0};
			}
		}
	}
}
