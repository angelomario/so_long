/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:41:45 by aquissan          #+#    #+#             */
/*   Updated: 2024/08/14 12:41:49 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	showimage(char ch, t_vars vars, t_point position)
{
	t_img	image;

	if (ch == '1')
		image = vars.pictures.world.wall;
	else if (ch == '0')
		image = vars.pictures.world.floor;
	else if (ch == 'C')
		image = vars.pictures.world.food;
	else if (ch == 'E')
		image = vars.pictures.world.door_close;
	else if (ch == 'P')
		image = vars.pictures.rogue_sr.img_1;
	else if (ch == 'N')
		image = vars.pictures.orc_sr.img_1;
	if (!ft_ch_in_str(ch, "10CEPN"))
		return ;
	mlx_put_image_to_window(vars.mlx, vars.window,
		image.img,
		position.x * (image.width),
		position.y * image.height);
}

void	create_image(t_vars *vars)
{
	vars->pictures.rogue_rr = set_rogue_run_right(*vars);
	vars->pictures.rogue_rl = set_rogue_run_left(*vars);
	vars->pictures.orc_rr = set_orc_run_right(*vars);
	vars->pictures.orc_rl = set_orc_run_left(*vars);
	vars->pictures.rogue_sr = set_rogue_standing_right(*vars);
	vars->pictures.rogue_sl = set_rogue_standing_left(*vars);
	vars->pictures.orc_sl = set_orc_standing_left(*vars);
	vars->pictures.orc_sr = set_orc_standing_right(*vars);
	vars->pictures.orc_ar = set_orc_atack_right(*vars);
	vars->pictures.orc_al = set_orc_atack_left(*vars);
	vars->pictures.world = set_world(*vars);
	vars->pictures.orc_ur = set_orc_up_right(*vars);
	vars->pictures.orc_ul = set_orc_up_left(*vars);
	vars->pictures.rogue_ur = set_rogue_up_right(*vars);
	vars->pictures.rogue_ul = set_rogue_up_left(*vars);
	vars->pictures.rogue_dl = set_rogue_death_l(*vars);
	vars->pictures.rogue_dr = set_rogue_death_r(*vars);
}
