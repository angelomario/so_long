/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 07:11:30 by aquissan          #+#    #+#             */
/*   Updated: 2024/08/28 07:12:24 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	enemy_right(t_vars vars, t_point position, t_enemy orc)
{
	if (vars.map[position.y][position.x + 1] == '0'
			|| vars.enemies[orc.index].next_img >= 4)
	{
		speed_enemy(vars, vars.pictures.orc_rr, position, orc);
		if (vars.enemies[orc.index].alter)
		{
			show_this_image(vars, vars.pictures.world.floor, position);
			vars.map[position.y][position.x] = '0';
			vars.map[position.y][position.x + 1] = 'N';
			vars.enemies[orc.index].alter = 0;
			vars.enemies[orc.index].orc_see = 3;
			position = (t_point){position.x + 1, position.y};
			update_position(&vars, vars.map);
			orc = vars.enemies[get_index(vars, position)];
		}
		leave_enemy(vars, vars.pictures.orc_rr, position, orc);
	}
}

void	enemy_left(t_vars vars, t_point position, t_enemy orc)
{
	if (vars.map[position.y][position.x - 1] == '0'
		|| vars.enemies[orc.index].next_img >= 4)
	{
		speed_enemy(vars, vars.pictures.orc_rl, position, orc);
		if (vars.enemies[orc.index].alter)
		{
			show_this_image(vars, vars.pictures.world.floor, position);
			vars.map[position.y][position.x] = '0';
			vars.map[position.y][position.x - 1] = 'N';
			vars.enemies[orc.index].alter = 0;
			vars.enemies[orc.index].orc_see = 2;
			position = (t_point){position.x - 1, position.y};
			update_position(&vars, vars.map);
			orc = vars.enemies[get_index(vars, position)];
		}
		leave_enemy(vars, vars.pictures.orc_rl, position, orc);
	}
}

void	enemy_up(t_vars vars, t_point position, t_enemy orc)
{
	if (vars.map[position.y - 1][position.x] == '0'
			|| vars.enemies[orc.index].next_img >= 4)
	{
		if (orc.orc_see == 3)
			speed_enemy(vars, vars.pictures.orc_ur, position, orc);
		else
			speed_enemy(vars, vars.pictures.orc_ul, position, orc);
		if (vars.enemies[orc.index].alter)
		{
			show_this_image(vars, vars.pictures.world.floor, position);
			vars.map[position.y][position.x] = '0';
			vars.map[position.y - 1][position.x] = 'N';
			vars.enemies[orc.index].alter = 0;
			position = (t_point){position.x, position.y - 1};
			update_position(&vars, vars.map);
			orc = vars.enemies[get_index(vars, position)];
		}
		if (orc.orc_see == 3)
			leave_enemy(vars, vars.pictures.orc_ur, position, orc);
		else
			leave_enemy(vars, vars.pictures.orc_ul, position, orc);
	}
}

void	enemy_down(t_vars vars, t_point position, t_enemy orc)
{
	if (vars.map[position.y + 1][position.x] == '0'
			|| vars.enemies[orc.index].next_img >= 4)
	{
		if (orc.orc_see == 3)
			leave_reverse_enemy(vars, vars.pictures.orc_ur, position, orc);
		else
			leave_reverse_enemy(vars, vars.pictures.orc_ul, position, orc);
		if (vars.enemies[orc.index].alter)
		{
			show_this_image(vars, vars.pictures.world.floor, position);
			vars.map[position.y][position.x] = '0';
			vars.map[position.y + 1][position.x] = 'N';
			vars.enemies[orc.index].alter = 0;
			position = (t_point){position.x, position.y + 1};
			update_position(&vars, vars.map);
			orc = vars.enemies[get_index(vars, position)];
		}
		if (orc.orc_see == 3)
			speed_reverse_enemy(vars, vars.pictures.orc_ur, position, orc);
		else
			speed_reverse_enemy(vars, vars.pictures.orc_ul, position, orc);
	}
}

void	enemy_attack(t_vars vars, t_point position, t_enemy orc)
{
	int	i;

	i = get_index(vars, position);
	if (orc.orc_see == 3)
		speed_p(vars, vars.pictures.orc_ar, position, orc);
	else
		speed_p(vars, vars.pictures.orc_al, position, orc);
	if (orc.orc_see == 3)
		leave_p(vars, vars.pictures.orc_ar, position, orc);
	else
		leave_p(vars, vars.pictures.orc_al, position, orc);
}
