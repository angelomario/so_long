/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reach_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:39:05 by aquissan          #+#    #+#             */
/*   Updated: 2024/09/06 13:39:32 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	death(t_vars vars, t_death p, t_point position)
{
	if (vars.status->next_img == 1)
		show_this_image(vars, p.img_1, position);
	if (vars.status->next_img == 2)
		show_this_image(vars, p.img_2, position);
	if (vars.status->next_img == 3)
		show_this_image(vars, p.img_3, position);
	if (vars.status->next_img == 4)
		show_this_image(vars, p.img_4, position);
	if (vars.status->next_img == 5)
		show_this_image(vars, p.img_5, position);
	g_timer_move++;
	if (g_timer_move >= (g_ter * 20))
	{
		if (vars.status->next_img == 5)
		{
			vars.status->next_img++;
			finish_game(&vars, 0);
		}
		if (vars.status->next_img <= 5)
			vars.status->next_img++;
		g_timer_move = 0;
	}
}

char	check_reach_way(t_vars vars, t_enemy orc, char direction, int dif)
{
	while (direction == 'R' && dif)
	{
		--dif;
		if (vars.map[orc.position.y][orc.position.x + dif] == '1')
			direction = '\0';
	}
	while (direction == 'E' && dif)
	{
		--dif;
		if (vars.map[orc.position.y][orc.position.x - dif] == '1')
			direction = '\0';
	}
	while (direction == 'U' && dif)
	{
		--dif;
		if (vars.map[orc.position.y - dif][orc.position.x] == '1')
			direction = '\0';
	}
	while (direction == 'D' && dif)
	{
		--dif;
		if (vars.map[orc.position.y + dif][orc.position.x] == '1')
			direction = '\0';
	}
	return (direction);
}

void	check_reach(t_vars vars, t_point rogue, t_point orc, int index)
{
	char	ch;

	ch = '\0';
	if (rogue.x > orc.x && rogue.y == orc.y)
		if ((rogue.x - orc.x) <= 3)
			ch = check_reach_way(vars, vars.enemies[index], 'R', (rogue.x
						- orc.x));
	if (rogue.x < orc.x && rogue.y == orc.y)
		if ((orc.x - rogue.x) <= 3)
			ch = check_reach_way(vars, vars.enemies[index], 'E', (orc.x
						- rogue.x));
	if (rogue.y > orc.y && rogue.x == orc.x)
		if ((rogue.y - orc.y) <= 3)
			ch = check_reach_way(vars, vars.enemies[index], 'D', (rogue.y
						- orc.y));
	if (rogue.y < orc.y && rogue.x == orc.x)
		if ((orc.y - rogue.y) <= 3)
			ch = check_reach_way(vars, vars.enemies[index], 'U', (orc.y
						- rogue.y));
	if (ch != '\0')
		vars.enemies[index].direction = ch;
}

void	detect_rogue(t_vars *vars)
{
	int		i;
	t_point	rp;
	t_point	op;

	i = ft_count_var_game(vars->map, 'N');
	while (i--)
	{
		rp = get_start_var(vars->map, 'P');
		op = vars->enemies[i].position;
		check_reach(*vars, rp, op, i);
	}
}

int	fee_animate(t_vars vars)
{
	int	i;

	i = 0;
	while (i < 4)
		free(vars.animate[i++]);
	free(vars.animate);
	return (1);
}
