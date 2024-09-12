/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia_enemy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:45:55 by aquissan          #+#    #+#             */
/*   Updated: 2024/08/29 10:46:36 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_wall(t_vars *vars, int index, char **map)
{
	t_point	p;
	char	ch;

	p = vars->enemies[index].position;
	ch = vars->enemies[index].direction;
	if (ch == 'R' && vars->enemies[index].in_move == 0)
		if (map[p.y][p.x + 1] != '0')
			vars->enemies[index].direction = '\0';
	if (ch == 'E' && vars->enemies[index].in_move == 0)
		if (map[p.y][p.x - 1] != '0')
			vars->enemies[index].direction = '\0';
	if (ch == 'U' && vars->enemies[index].in_move == 0)
		if (map[p.y - 1][p.x] != '0')
			vars->enemies[index].direction = '\0';
	if (ch == 'D' && vars->enemies[index].in_move == 0)
		if (map[p.y + 1][p.x] != '0')
			vars->enemies[index].direction = '\0';
}

int	direction_attack(t_enemy enemies, char direction)
{
	if (direction == 'R')
		return (3);
	if (direction == 'E')
		return (2);
	return (enemies.orc_see);
}

void	time_to_attack(t_vars *vars, int index, t_point position)
{
	char	ch;

	ch = '\n';
	if (vars->map[position.y][position.x + 1] == 'P')
		ch = 'R';
	else if (vars->map[position.y][position.x - 1] == 'P')
		ch = 'E';
	else if (vars->map[position.y + 1][position.x] == 'P')
		ch = 'D';
	else if (vars->map[position.y - 1][position.x] == 'P')
		ch = 'U';
	else
		vars->enemies[index].to_attack = 0;
	if (ch != '\n')
		vars->enemies[index].to_attack++;
	if (vars->enemies[index].to_attack >= (vars->enemies[index].teo * 15))
	{
		vars->enemies[index].stop_attack = 1;
		if (vars->status->is_dead == 0)
			vars->enemies[index].in_move = 1;
		vars->enemies[index].orc_see = direction_attack(vars->enemies[index],
				ch);
		vars->status->is_dead = 1;
	}
}

void	direction_enemy(t_vars *vars, int i)
{
	if (vars->enemies[i].stop_attack && vars->status->is_dead)
		enemy_attack(*vars, vars->enemies[i].position, vars->enemies[i]);
	else if (vars->enemies[i].direction == 'R')
		enemy_right(*vars, vars->enemies[i].position, vars->enemies[i]);
	else if (vars->enemies[i].direction == 'E')
		enemy_left(*vars, vars->enemies[i].position, vars->enemies[i]);
	else if (vars->enemies[i].direction == 'D')
		enemy_down(*vars, vars->enemies[i].position, vars->enemies[i]);
	else if (vars->enemies[i].direction == 'U')
		enemy_up(*vars, vars->enemies[i].position, vars->enemies[i]);
}

void	brain_enemy(t_vars *vars)
{
	int	i;

	i = ft_count_var_game(vars->map, 'N');
	while (i--)
	{
		update_position(vars, vars->map);
		check_wall(vars, i, vars->map);
		time_to_attack(vars, i, vars->enemies[i].position);
		direction_enemy(vars, i);
	}
	if (vars->timer_pause >= 5)
	{
		reset_enemies_directions(vars);
		vars->timer_pause = 0;
	}
	if (vars->status->is_dead)
		rogue_die(*vars, get_start_var(vars->map, 'P'));
}
