/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 08:57:12 by aquissan          #+#    #+#             */
/*   Updated: 2024/08/26 08:59:20 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	animation(t_vars *vars)
{
	if (vars->status->colate == vars->status->total)
		show_this_image(*vars, vars->pictures.world.door_open,
			get_start_var(vars->map, 'E'));
	if (vars->direction[0])
	{
		vars->status->in_move = 1;
	}
	move_all_diretion(vars);
	brain_enemy(vars);
	if (g_timer >= 30000)
	{
		show_status(*vars);
		vars->timer_pause++;
		if (g_next == 4)
			g_next = 0;
		on_read_map(*vars, 'N');
		g_next++;
		g_timer = 0;
	}
	g_timer++;
	return (0);
}

void	speed_r(t_vars vars, t_run p, t_point position)
{
	if (vars.status->next_img > 6)
		vars.status->next_img = 1;
	if (vars.status->next_img == 4 && vars.status->in_move)
		show_this_image(vars, p.img_6, position);
	if (vars.status->next_img == 5 && vars.status->in_move)
		show_this_image(vars, p.img_5, position);
	if (vars.status->next_img == 6 && vars.status->in_move)
		show_this_image(vars, p.img_4, position);
	if (vars.status->next_img >= 4)
		g_timer_move++;
	if (g_timer_move >= g_ter)
	{
		if (vars.status->next_img == 6)
		{
			vars.status->in_move = 0;
			rm_direction(vars.direction);
			vars.status->next_img = 1;
		}
		if (vars.status->next_img >= 4)
			vars.status->next_img++;
		g_timer_move = 0;
	}
}

void	leave_r(t_vars vars, t_run p, t_point position)
{
	if (vars.status->next_img == 1 && vars.status->in_move)
		show_this_image(vars, p.img_3, position);
	if (vars.status->next_img == 2 && vars.status->in_move)
		show_this_image(vars, p.img_2, position);
	if (vars.status->next_img == 3 && vars.status->in_move)
		show_this_image(vars, p.img_1, position);
	if (vars.status->next_img <= 3)
		g_timer_move++;
	if (g_timer_move >= g_ter)
	{
		if (vars.status->next_img == 3)
		{
			vars.status->alter = 1;
			vars.status->next_img = 4;
		}
		g_timer_move = 0;
		if (vars.status->next_img <= 3)
			vars.status->next_img++;
	}
}

void	speed(t_vars vars, t_run p, t_point position)
{
	if (vars.status->next_img == 1 && vars.status->in_move)
		show_this_image(vars, p.img_4, position);
	if (vars.status->next_img == 2 && vars.status->in_move)
		show_this_image(vars, p.img_5, position);
	if (vars.status->next_img == 3 && vars.status->in_move)
		show_this_image(vars, p.img_6, position);
	if (vars.status->next_img <= 3)
		g_timer_move++;
	if (g_timer_move >= g_ter)
	{
		if (vars.status->next_img == 3)
		{
			vars.status->alter = 1;
			vars.status->next_img++;
		}
		else if (vars.status->next_img <= 3)
			vars.status->next_img++;
		g_timer_move = 0;
	}
}

void	leave(t_vars vars, t_run p, t_point position)
{
	if (vars.status->next_img == 4 && vars.status->in_move)
		show_this_image(vars, p.img_1, position);
	if (vars.status->next_img == 5 && vars.status->in_move)
		show_this_image(vars, p.img_2, position);
	if (vars.status->next_img == 6 && vars.status->in_move)
		show_this_image(vars, p.img_3, position);
	if (vars.status->next_img >= 4)
		g_timer_move++;
	if (g_timer_move >= g_ter)
	{
		if (vars.status->next_img == 6)
		{
			vars.status->next_img = 1;
			vars.status->in_move = 0;
			rm_direction(vars.direction);
		}
		else if (vars.status->next_img >= 4)
			vars.status->next_img++;
		g_timer_move = 0;
	}
}
