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

#include "../includes/so_long_bonus.h"

void	move_right(t_vars vars, t_point position)
{
	if (vars.map[position.y][position.x + 1] == 'E'
			&& vars.status->next_img == 1)
		finish_game(&vars, 1);
	if (vars.map[position.y][position.x + 1] == '0'
			|| vars.map[position.y][position.x + 1] == 'C'
			|| vars.status->next_img >= 4)
	{
		speed(vars, vars.pictures.rogue_rr,
			get_start_var(vars.map, 'P'));
		if (vars.status->alter)
		{
			vars.status->moves++;
			if (vars.map[position.y][position.x + 1] == 'C')
				vars.status->colate++;
			show_this_image(vars, vars.pictures.world.floor, position);
			vars.map[position.y][position.x + 1] = 'P';
			vars.map[position.y][position.x] = '0';
			vars.status->alter = 0;
		}
		leave(vars, vars.pictures.rogue_rr, get_start_var(vars.map, 'P'));
	}
}

void	move_left(t_vars vars, t_point position)
{
	if (vars.map[position.y][position.x - 1] == 'E'
			&& vars.status->next_img == 1)
		finish_game(&vars, 1);
	if (vars.map[position.y][position.x - 1] == '0'
			|| vars.map[position.y][position.x - 1] == 'C'
			|| vars.status->next_img >= 4)
	{
		speed(vars, vars.pictures.rogue_rl, get_start_var(vars.map, 'P'));
		if (vars.status->alter)
		{
			if (vars.map[position.y][position.x - 1] == 'C')
				vars.status->colate++;
			vars.status->moves++;
			show_this_image(vars, vars.pictures.world.floor, position);
			vars.map[position.y][position.x - 1] = 'P';
			vars.map[position.y][position.x] = '0';
			vars.status->alter = 0;
		}
		leave(vars, vars.pictures.rogue_rl, get_start_var(vars.map, 'P'));
		g_timer_move++;
	}
}

void	move_up(t_vars vars, t_point position)
{
	if (vars.map[position.y - 1][position.x] == 'E'
			&& vars.status->next_img == 1)
		finish_game(&vars, 1);
	if (vars.map[position.y - 1][position.x] == '0' || vars.map[position.y - 1]
			[position.x] == 'C' || vars.status->next_img >= 4)
	{
		if (vars.rogue_see[0] == 1)
			speed(vars, vars.pictures.rogue_ur, get_start_var(vars.map, 'P'));
		else
			speed(vars, vars.pictures.rogue_ul, get_start_var(vars.map, 'P'));
		if (vars.status->alter)
		{
			if (vars.map[position.y - 1][position.x] == 'C')
				vars.status->colate++;
			vars.status->moves++;
			show_this_image(vars, vars.pictures.world.floor, position);
			vars.map[position.y - 1][position.x] = 'P';
			vars.map[position.y][position.x] = '0';
			vars.status->alter = 0;
		}
		if (vars.rogue_see[0] == 1)
			leave(vars, vars.pictures.rogue_ur, get_start_var(vars.map, 'P'));
		else
			leave(vars, vars.pictures.rogue_ul, get_start_var(vars.map, 'P'));
	}
}

void	move_down(t_vars vars, t_point position)
{
	if (vars.map[position.y + 1][position.x] == 'E'
			&& vars.status->next_img == 1)
		finish_game(&vars, 1);
	if (vars.map[position.y + 1][position.x] == '0' || vars.map[position.y + 1]
			[position.x] == 'C' || vars.status->next_img >= 4)
	{
		if (vars.rogue_see[0] == 1)
			leave_r(vars, vars.pictures.rogue_ur, get_start_var(vars.map, 'P'));
		else
			leave_r(vars, vars.pictures.rogue_ul, get_start_var(vars.map, 'P'));
		if (vars.status->alter)
		{
			if (vars.map[position.y + 1][position.x] == 'C')
				vars.status->colate++;
			vars.status->moves++;
			show_this_image(vars, vars.pictures.world.floor, position);
			vars.map[position.y + 1][position.x] = 'P';
			vars.map[position.y][position.x] = '0';
			vars.status->alter = 0;
		}
		if (vars.rogue_see[0] == 1)
			speed_r(vars, vars.pictures.rogue_ur, get_start_var(vars.map, 'P'));
		else
			speed_r(vars, vars.pictures.rogue_ul, get_start_var(vars.map, 'P'));
	}
}

int	move(int key_code, t_vars *vars)
{
	if (key_code == 65307)
		end_game(*vars, get_start_var(vars->map, 'P'));
	if ((char)key_code == 'S' && !vars->status->is_dead)
	{
		vars->rogue_see[0] = 1;
		set_direction(*vars, 'R');
	}
	else if ((char)key_code == 'T' && !vars->status->is_dead)
	{
		set_direction(*vars, 'D');
	}
	else if ((char)key_code == 'Q' && !vars->status->is_dead)
	{
		vars->rogue_see[0] = 0;
		set_direction(*vars, 'E');
	}
	else if ((char)key_code == 'R' && !vars->status->is_dead)
		set_direction(*vars, 'U');
	show_status(*vars);
	return (1);
}
