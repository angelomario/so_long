/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:09:23 by aquissan          #+#    #+#             */
/*   Updated: 2024/09/02 16:09:49 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	showmap(t_vars vars)
{
	int		x;
	int		y;
	t_point	pos;

	y = 0;
	while (vars.map[y] != NULL)
	{
		x = 0;
		while (vars.map[y][x] != '\0')
		{
			pos.x = x;
			pos.y = y;
			showimage(vars.map[y][x], vars, pos);
			x++;
		}
		y++;
	}
}

void	extra(t_vars *vars, int res)
{
	if (!res)
	{
		vars->status->moves++;
		show_status(*vars);
		ft_printf("\033[32mYou win!\n\033[0m");
	}
	else
		ft_printf("\033[31mYou lose!\n\033[0m");
}

void	ft_img(t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->window,
		vars->pictures.world.wall.img,
		x * 40, y * 40);
}

void	finish_game(t_vars	*vars, int res)
{
	int	x;
	int	y;
	int	i;

	y = -1;
	if (ft_count_var_game(vars->map, 'C') != 0 && vars->status->is_dead == 0)
		return ;
	extra(vars, vars->status->is_dead);
	while (vars->map[++y] != NULL)
	{
		x = -1;
		while (vars->map[y][++x])
		{
			if (vars->map[y][x] != 'P')
			{
				i = 0;
				while (i <= 3000)
				{
					ft_img(vars, x, y);
					i++;
				}
			}
		}
	}
	ft_quick_game(vars);
}

void	rogue_die(t_vars vars, t_point position)
{
	if (vars.status->is_dead)
	{
		if (vars.rogue_see[0] == 0)
			death(vars, vars.pictures.rogue_dl, position);
		else
			death(vars, vars.pictures.rogue_dr, position);
	}
}
