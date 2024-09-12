/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_enemies_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:33:56 by aquissan          #+#    #+#             */
/*   Updated: 2024/08/28 15:34:27 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	speed_reverse_enemy(t_vars vars, t_run p, t_point position, t_enemy orc)
{
	int	index;

	index = get_index(vars, position);
	if (vars.enemies[index].next_img > 6)
		vars.enemies[index].next_img = 1;
	if (vars.enemies[index].next_img == 4 && vars.enemies[index].in_move)
		show_this_image(vars, p.img_6, position);
	if (vars.enemies[index].next_img == 5 && vars.enemies[index].in_move)
		show_this_image(vars, p.img_5, position);
	if (vars.enemies[index].next_img == 6 && vars.enemies[index].in_move)
		show_this_image(vars, p.img_4, position);
	if (vars.enemies[index].next_img >= 4)
		vars.enemies[index].timer_enemy++;
	if (vars.enemies[index].timer_enemy >= vars.enemies[index].teo)
	{
		if (vars.enemies[index].next_img == 6)
		{
			vars.enemies[index].in_move = 0;
			vars.enemies[index].direction = '\0';
			vars.enemies[index].next_img = 1;
		}
		else if (vars.enemies[index].next_img >= 4)
			vars.enemies[index].next_img++;
		vars.enemies[index].timer_enemy = 0;
	}
}

void	leave_reverse_enemy(t_vars vars, t_run p, t_point position, t_enemy orc)
{
	int	index;

	index = get_index(vars, position);
	if (vars.enemies[index].next_img == 1 && vars.enemies[index].in_move)
		show_this_image(vars, p.img_3, position);
	if (vars.enemies[index].next_img == 2 && vars.enemies[index].in_move)
		show_this_image(vars, p.img_2, position);
	if (vars.enemies[index].next_img == 3 && vars.enemies[index].in_move)
		show_this_image(vars, p.img_1, position);
	if (vars.enemies[index].next_img <= 3)
		vars.enemies[index].timer_enemy++;
	if (vars.enemies[index].timer_enemy >= vars.enemies[index].teo)
	{
		if (vars.enemies[index].next_img == 3)
		{
			vars.enemies[index].alter = 1;
			vars.enemies[index].next_img++;
		}
		else if (vars.enemies[index].next_img < 3)
			vars.enemies[index].next_img++;
		vars.enemies[index].timer_enemy = 0;
	}
}

void	speed_enemy(t_vars vars, t_run p, t_point position, t_enemy orc)
{
	int	index;

	index = get_index(vars, position);
	if (vars.enemies[index].next_img == 1 && vars.enemies[index].in_move)
		show_this_image(vars, p.img_4, position);
	if (vars.enemies[index].next_img == 2 && vars.enemies[index].in_move)
		show_this_image(vars, p.img_5, position);
	if (vars.enemies[index].next_img == 3 && vars.enemies[index].in_move)
		show_this_image(vars, p.img_6, position);
	if (vars.enemies[index].next_img <= 3)
		vars.enemies[index].timer_enemy++;
	if (vars.enemies[index].timer_enemy >= vars.enemies[index].teo)
	{
		if (vars.enemies[index].next_img == 3)
		{
			vars.enemies[index].alter = 1;
			vars.enemies[index].next_img++;
		}
		else if (vars.enemies[index].next_img < 3)
			vars.enemies[index].next_img++;
		vars.enemies[index].timer_enemy = 0;
	}
}

void	leave_enemy(t_vars vars, t_run p, t_point position, t_enemy orc)
{
	int	index;

	index = get_index(vars, position);
	if (vars.enemies[index].next_img == 4 && vars.enemies[index].in_move)
		show_this_image(vars, p.img_1, position);
	if (vars.enemies[index].next_img == 5 && vars.enemies[index].in_move)
		show_this_image(vars, p.img_2, position);
	if (vars.enemies[index].next_img == 6 && vars.enemies[index].in_move)
		show_this_image(vars, p.img_3, position);
	if (vars.enemies[index].next_img >= 4)
		vars.enemies[index].timer_enemy++;
	if (vars.enemies[index].timer_enemy >= vars.enemies[index].teo)
	{
		if (vars.enemies[index].next_img == 6)
		{
			vars.enemies[index].next_img = 1;
			vars.enemies[index].in_move = 0;
			vars.enemies[index].direction = '\0';
		}
		else if (vars.enemies[index].next_img >= 4)
			vars.enemies[index].next_img++;
		vars.enemies[index].timer_enemy = 0;
	}
}
