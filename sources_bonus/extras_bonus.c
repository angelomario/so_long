/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:05:30 by aquissan          #+#    #+#             */
/*   Updated: 2024/09/06 14:05:48 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	get_index(t_vars vars, t_point position)
{
	int	index;
	int	i;

	index = ft_count_var_game(vars.map, 'N');
	i = -1;
	if (index <= 0)
		return (0);
	while (++i < index)
	{
		if (vars.enemies[i].position.x == position.x
			&& vars.enemies[i].position.y == position.y)
		{
			return (i);
		}
	}
	return (0);
}

void	leave_p(t_vars vars, t_atack p, t_point position, t_enemy orc)
{
	int	index;

	index = get_index(vars, position);
	if (vars.enemies[index].next_img == 4 && vars.enemies[index].in_move)
		show_this_image(vars, p.img_4, position);
	if (vars.enemies[index].next_img == 5 && vars.enemies[index].in_move)
		show_this_image(vars, p.img_5, position);
	if (vars.enemies[index].next_img >= 4)
		vars.enemies[index].timer_enemy++;
	if (vars.enemies[index].timer_enemy >= vars.enemies[index].teo)
	{
		if (vars.enemies[index].next_img == 5)
		{
			vars.enemies[index].next_img = 1;
			vars.enemies[index].in_move = 0;
		}
		else if (vars.enemies[index].next_img >= 4)
			vars.enemies[index].next_img++;
		vars.enemies[index].timer_enemy = 0;
	}
}

void	speed_p(t_vars vars, t_atack p, t_point position, t_enemy orc)
{
	int	index;

	index = get_index(vars, position);
	if (vars.enemies[index].next_img == 1 && vars.enemies[index].in_move)
		show_this_image(vars, p.img_1, position);
	if (vars.enemies[index].next_img == 2 && vars.enemies[index].in_move)
		show_this_image(vars, p.img_2, position);
	if (vars.enemies[index].next_img == 3 && vars.enemies[index].in_move)
	{
		show_this_image(vars, p.img_3, position);
	}
	if (vars.enemies[index].next_img <= 3)
		vars.enemies[index].timer_enemy++;
	if (vars.enemies[index].timer_enemy >= vars.enemies[index].teo)
	{
		if (vars.enemies[index].next_img <= 3)
			vars.enemies[index].next_img++;
		vars.enemies[index].timer_enemy = 0;
	}
}
